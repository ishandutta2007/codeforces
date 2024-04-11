#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int m1 = 998244353, m2 = 1e9 + 9;
const int p1 = 131, p2 = 13331;
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    return {(a.first + b.first) % m1, (a.second + b.second) % m2};
}
pair<int, int> mul(pair<int, int> a, int b) {
    return {1ll * a.first * b % m1, 1ll * a.second * b % m2};
}
int solve(string s) {
    int n = s.size();
    vector<int> pw(n); pw[0] = 1;
    for(int i = 1; i < n; ++i) pw[i] = 2ll * pw[i - 1] % mod;
    function<tuple<int,int,pair<int,int>>(int)> dfs = [&](int rt) -> tuple<int,int,pair<int,int>> {
        if(2 * rt - 1 >= s.size()) return {1, 1, {s[rt - 1] - 'A', s[rt - 1] - 'A'}};
        auto [lc, ls, lh] = dfs(rt * 2);
        auto [rc, rs, rh] = dfs(rt * 2 + 1);
        ll cc = lh == rh ? 1ll * lc * rc % mod : 2ll * lc * rc % mod;
        if(lh > rh) swap(lh, rh);
        int sz = ls + rs + 1;
        pair<int,int> hh = add(mul(add(mul(lh, pw[ls]), rh), 2), {s[rt - 1] - 'A', s[rt - 1] - 'A'});
        return {cc, sz, hh};
    };
    return get<0>(dfs(1));
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s) << '\n';
}