#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int main() {
    int k, a, h;
    cin >> k >> a >> h;
    int m = 1 << k;
    vector<int> rk {1};
    for(int i = 0; i < k; ++i) rk.push_back((1 << i) + 1);
    vector<ll> pw(k + 1);
    for(int i = 0; i <= k; ++i) {
        pw[i] = 1;
        for(int j = 0; j < rk[i]; ++j) pw[i] = pw[i] * a % mod;
    }
    vector<pair<ll,int>> up;
    map<pair<ll,int>,vector<int>> dp, up2;
    for(int i = 0; i < (1 << (m / 2 - 1)); ++i) {
        // #participants : m / 2
        // #games : m / 2 - 1
        // #turn : k - 1
        // calculate hash and winner
        vector<int> cur, res(m / 2);
        for(int j = 0; j < m / 2; ++j) cur.push_back(j);
        int x = i;
        ll hsh1 = 0, hsh2 = 0;
        for(int j = 0; j < k - 1; ++j) {
            vector<int> ncur;
            for(int p = 0; p < cur.size(); p += 2) {
                if(x & 1) {
                    ncur.push_back(cur[p]);
                    res[cur[p + 1]] = rk[k - j];
                    hsh1 += pw[k - j] * (cur[p+1] + 1) % mod;
                    hsh2 += pw[k - j] * (cur[p+1] + 1 + m / 2) % mod;
                } else {
                    ncur.push_back(cur[p + 1]);
                    res[cur[p]] = rk[k - j];
                    hsh1 += pw[k - j] * (cur[p] + 1) % mod;
                    hsh2 += pw[k - j] * (cur[p] + 1 + m / 2) % mod;
                }
                x >>= 1;
            }
            cur = move(ncur);
        }
        hsh1 %= mod; hsh2 %= mod;
        assert(cur.size() == 1);
        up.push_back({hsh1, cur[0] + 1});
        up2[{hsh1, cur[0] + 1}] = res;
        dp[{hsh2, cur[0] + 1 + m / 2}] = res;
    }
    for(auto [hsh, p] : up) {
        for(int q = m / 2 + 1; q <= m; ++q) {
            // p is winner
            {
                // p : 1, q : 2
                ll hsh2 = (h - hsh - p * pw[0] - q * pw[1]) % mod;
                if(hsh2 < 0) hsh2 += mod;
                if(dp.count({hsh2, q})) {
                    vector<int> v1 = up2[{hsh, p}], v2 = dp[{hsh2, q}];
                    for(int &i : v1) if(i == 0) i = 1;
                    for(int &i : v2) if(i == 0) i = 2;
                    for(int i : v1) cout << i << " ";
                    for(int i : v2) cout << i << " ";
                    cout << '\n';
                    exit(0);
                }
            }
            // q is winner
            {
                ll hsh2 = (h - hsh - p * pw[1] - q * pw[0]) % mod;
                if(hsh2 < 0) hsh2 += mod;
                if(dp.count({hsh2, q})) {
                    vector<int> v1 = up2[{hsh, p}], v2 = dp[{hsh2, q}];
                    for(int &i : v1) if(i == 0) i = 2;
                    for(int &i : v2) if(i == 0) i = 1;
                    for(int i : v1) cout << i << " ";
                    for(int i : v2) cout << i << " ";
                    cout << '\n';
                    exit(0);
                }
            }
        }
    }
    cout << -1 << endl;
}