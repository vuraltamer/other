#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <list>
#include <algorithm>

using namespace std;
 
// function tanimlari yapilir.
int zarAt();
int zarlariAt();
int zarAtmayaBasla(); 
 
// main methodu 
int main () {
 
   zarAtmayaBasla();
 
   return 0;
}

int zarAtmayaBasla() {

    std::string zarAtilsinMi = "E";
    
    int toplam = 0; // Zarlarin toplamini tutaruz
    int tur = 1; // Zar atim isleminin kac defa tekrarlayacağini tutuyoruz.
    
    list<int> gelenList; // Tekrarlanan toplam degerlerini listede tutuyoruz.
    
    while (zarAtilsinMi == "E") {
        if (tur == 1) { //İlk defa atilmissa bu loopa 
                
            cout << "İlk tur atiliyor " << endl;
            toplam = zarlariAt(); // Zarlar atilir
            if (toplam == 7 || toplam == 11) { // 7 ya da 11 gelirse
                cout << "Kazandin! Zarlarin toplami : " << toplam << endl;
                return 0;
            } else if (toplam == 2 || toplam == 3 || toplam == 12) { // 2,3 ve 12 gelirse
                cout << "Kaybettin! Zarlarin toplami : " << toplam << endl;
                return 0;
            } else { // Diğer ihtimaller icin
                gelenList.push_front(toplam);
                tur++;
                cout << "Zar atmaya devam. " << tur << ". tur atiliyor." << endl;
            }
        } else { //İlk turda sonuc belirlenememisse  bu loopa
            if (toplam == 7 || toplam == 11) { // 7 ve 11 gelirse 
                cout << "Kaybettin! Zarlarin toplami : " << toplam << endl;
                return 0;
            } else if (std::find(gelenList.begin(), gelenList.end(), toplam) != gelenList.end()) { // tekrarli toplami kontrol ediyoruz
                cout << "Kazandin! Zarlarin toplami : " << toplam << endl;
                return 0;
            } else {
                gelenList.push_front(toplam);
                tur++;
                cout << "Zar atmaya devam. " << tur << ". tur atiliyor." << endl;
	        }
        }
        
        std::cout << "Tekrar zar atilsin mi? Evet icin 'E' Hayir icin herhangi bir tusa basiniz. ";
        getline (std::cin, zarAtilsinMi);
        
        
        if (zarAtilsinMi == "E") { // Zar atimina devam edilip edilmeyecegini kontrol ediyoruz.
            toplam = zarlariAt(); // Sonuc yoksa yeniden zar atilir.
        } else {
            cout << "Zar atimi sonlandirilmistir.";
        }
    }
    
}

// İkili atilan zarlarin toplam sonucunu return eder.
int zarlariAt() {
   int zar = zarAt();
   srand(time(NULL));
   int zar1 = zarAt();
   int top = zar + zar1;
   cout << "Zarlar atildi : " << zar << " ve " << zar1 << " . Toplam : " << top << endl;
   return top;
}
 
// Tek atilan zarin sonucunu return eder.
int zarAt() {
   return rand() % 6 + 1; 
}
