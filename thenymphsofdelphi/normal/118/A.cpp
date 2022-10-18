#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main(){
    string a;
    char c;
    cin >> a;
    int len = a.length(), i;
    for (i = 0; i < len; i++){
        c = a[i];
        if (isupper(c)) c = (char)((int)c + 32);
        a[i] = c;
        if (a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'y') cout << "." << a[i];
    }
}