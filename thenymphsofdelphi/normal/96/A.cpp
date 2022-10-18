#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int len, i;
    string a;
    cin >> a;
    len = a.length();
    if (len < 7){
        cout << "NO";
        return 0;
    }
    for (i = 6; i < len; i++){
        if (a[i] == a[i-1] && a[i] == a[i-2] && a[i] == a[i-3] && a[i] == a[i-4] && a[i] == a[i-5] && a[i] == a[i-6]){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}