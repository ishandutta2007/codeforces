#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++){
        if (i == 0 && a[i] == '9'){
            continue;
        }
        if ((a[i] - '0') > 9 - (a[i] - '0')){
            a[i] = (char)('0' + (9 - (a[i] - '0')));
        }
    }
    cout << a;
}