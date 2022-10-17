#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int s = a[0];
        for(int i : a) s &= i;
        for(int &i : a) i ^= s;
        int c = 0;
        for(int i : a) if(!i) ++c;
        ll ans = 1ll * c * (c - 1) / 2;
        ans %= mod;
        for(int i = 1; i <= n - 2; ++i) ans = ans * i % mod;
        ans = ans * 2 % mod;
        cout << ans << endl;
    }
}