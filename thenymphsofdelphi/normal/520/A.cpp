#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;

int main(){
    int n, i, x;
    cin >> n;
    string a;
    cin >> a;
    if (n < 26){
        cout << "NO";
        return 0;
    }
    bool b[26];
    for (i = 0; i < 26; i++){
        b[i] = false;
    }
    for (i = 0; i < n; i++){
        a[i] = tolower(a[i]);
        x = (int)a[i] - 97;
        b[x] = true;
    }
    for (i = 0; i < 26; i++){
        if (b[i] == false){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}