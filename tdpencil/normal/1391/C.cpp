#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;
int main() {
    ll n; cin >> n;
    ll fact[n+1] = {1};
    ll t = 1;
    ll cur = 1;
    for(ll i=1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
        if(i>=2) cur <<= 1;
        cur %= mod;
    }
    if(cur < 0) cur += mod;
    
    cout << (fact[n] - cur < 0 ? fact[n] - cur + mod : fact[n] - cur) % mod << "\n";
}