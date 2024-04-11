#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<ll> pw(n + 1);
    pw[0] = 1; for(int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % mod;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(x == 0) {
        ll ans = 0;
        map<int, int> cnt;
        for(int i : a) cnt[i] += 1;
        for(auto [p, v] : cnt) {
            ans += pw[v] - 1;
        }
        cout << ans % mod << '\n';
        return 0;
    }
    int h = 31 - __builtin_clz(x);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i) {
        mp[a[i] & ~((1 << (h + 1)) - 1)].push_back(a[i]);
    }
    ll ans = 0;
    for(auto [p, c] : mp) {
        vector<int> l, r;
        for(int i : c) {
            if(i >> h & 1) l.push_back(i);
            else r.push_back(i);
        }
        ans += pw[l.size()] - 1 + pw[r.size()] - 1;
        function<ll(vector<int>, vector<int>, int)> solve = [&](vector<int> l, vector<int> r, int b) -> ll {
            if(l.empty() || r.empty()) return 0;
            if(b < 0) return (pw[l.size()] - 1) * (pw[r.size()] - 1) % mod;
            vector<int> l0, l1, r0, r1;
            for(int i : l) {
                if(i >> b & 1) l0.push_back(i);
                else l1.push_back(i);
            }
            for(int i : r) {
                if(i >> b & 1) r0.push_back(i);
                else r1.push_back(i);
            }
            ll ret = 0;
            if(x >> b & 1) {
                ll p = solve(l0, r1, b - 1);
                ll q = solve(l1, r0, b - 1);
                ret += (pw[l0.size()] - 1) * (pw[r0.size()] - 1) % mod + (pw[l1.size()] - 1) * (pw[r1.size()] - 1) % mod;
                ret += p * q % mod + p * (pw[r0.size()] + pw[l1.size()] - 1) % mod + q * (pw[r1.size()] + pw[l0.size()] - 1) % mod;
            } else {
                ll p = solve(l0, r0, b - 1);
                ll q = solve(l1, r1, b - 1);
                ret += p + q;
            }
            return ret % mod;
        };
        ans += solve(l, r, h - 1);
    }
    ans %= mod;
    cout << ans << '\n';
}