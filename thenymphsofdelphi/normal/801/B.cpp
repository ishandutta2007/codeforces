#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    int n;
    cin >> a >> b;
    c = b;
    n = a.length();
    for (int i = 0; i < n; i++){
        if (b[i] > a[i]){
            cout << -1;
            return 0;
        }
        if (b[i] == a[i]){
            c[i] = 'z';
        }
    }
    cout << c;
}