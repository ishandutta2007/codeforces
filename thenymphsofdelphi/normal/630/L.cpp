#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e5;

signed main(){
    int n, a, b, c, d, e, ans = 1;
    cin >> n;
    e = n % 10;
    n /= 10;
    d = n % 10;
    n /= 10;
    c = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    a = n % 10;
    n = a * 10000 + c * 1000 + e * 100 + d * 10 + b;
    for (int i = 0; i < 5; i++){
        ans = (ans * n) % mod;
    }
    if (ans < 10000){
        cout << '0';
    }
    if (ans < 1000){
        cout << '0';
    }
    if (ans < 100){
        cout << '0';
    }
    if (ans < 10){
        cout << '0';
    }
    cout << ans;
}