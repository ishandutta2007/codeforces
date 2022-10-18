#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int dif = 0;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++){
        if (a[i] != b[i]) dif++;
    }
    if (dif % 2 == 1){
        cout << "impossible";
        return 0;
    }
    dif /= 2;
    for (int i = 0; i < a.length(); i++){
        if (dif > 0 && a[i] != b[i]){
            dif--;
            a[i] = b[i];
        }
    }
    cout << a;
}