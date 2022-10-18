#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        if (a == 1) cout << 0;
        else if (a == 2) cout << b;
        else cout << 2 * b;
        cout << endl;
    }
}