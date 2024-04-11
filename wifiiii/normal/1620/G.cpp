#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(26));
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < 26; ++j) {
            a[i][j] = count(s.begin(), s.end(), 'a' + j);
        }
    }
    vector<int> mn(26, inf), b(1 << n);
    function<void(int,int)> dfs = [&](int p, int s) {
        if(p == n) {
            int x = 1;
            for(int i = 0; i < 26; ++i) {
                x = 1ll * x * (mn[i] + 1) % mod;
            }
            b[s] = __builtin_popcount(s) & 1 ? x : mod - x;
            return;
        }
        dfs(p + 1, s);
        auto pmn = mn;
        for(int i = 0; i < 26; ++i) {
            mn[i] = min(mn[i], a[p][i]);
        }
        dfs(p + 1, s + (1 << p));
        mn = pmn;
    };
    dfs(0, 0);
    b[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 1 << n; ++j) {
            if(j >> i & 1) {
                (b[j] += b[j ^ (1 << i)]) >= mod ? b[j] -= mod : 0;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i < 1 << n; ++i) {
        int cnt = 0, sum = 0;
        for(int j = 0; j < n; ++j) {
            if(i >> j & 1) {
                cnt += 1;
                sum += j + 1;
            }
        }
        ans ^= 1ll * b[i] * cnt * sum;
    }
    cout << ans << '\n';
}