#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e2 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1ll) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int t = 0;
    for (auto v : s){
        t *= 2;
        t += v - '0';
        t %= mod;
    }
    cout << (t * binpow(2, s.length() - 1)) % mod;
}