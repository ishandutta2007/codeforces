#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n, i, len;
    cin >> n;
    string a;
    for (i = 0; i < n; i++){
        cin >> a;
        len = a.length();
        if (len > 10) cout << a[0] << len - 2 << a[len - 1] << endl;
        else cout << a << endl;
    }
}