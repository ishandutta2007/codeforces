#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a, b;
    cin >> a >> b;
    int c = 1, mod = 10;
    for (int i = a + 1; i <= b; i++){
        c = (c * i) % mod;
        if (c == 0){
            cout << 0;
            return 0;
        }
    }
    cout << c;
}