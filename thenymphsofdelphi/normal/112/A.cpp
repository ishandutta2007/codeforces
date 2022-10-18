#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int len = a.length(), i;
    for (i = 0; i < len; i++){
        if (isupper(a[i])) a[i] = (char)((int)a[i] + 32);
        if (isupper(b[i])) b[i] = (char)((int)b[i] + 32);
    }
    if (a.compare(b) > 0) cout << "1";
    else if (a.compare(b) < 0) cout << "-1";
    else cout << "0";
}