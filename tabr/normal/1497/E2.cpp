#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const int MAX = 10000100;
int spf[MAX];
bool is_prime[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(is_prime, 1, MAX);
    is_prime[0] = is_prime[1] = false;
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            spf[i] = i;
            if (1LL * i * i >= MAX) {
                continue;
            }
            for (int j = i * i; j < MAX; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
    vector<int> x(MAX);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int j;
            cin >> j;
            if (x[j]) {
                a[i] = x[j];
            }
            int t = 1;
            int jj = j;
            while (spf[j] != 1) {
                int s = spf[j];
                int l = 0;
                while (j % s == 0) {
                    j /= s;
                    l ^= 1;
                }
                if (l) {
                    t *= s;
                }
            }
            a[i] = x[jj] = t;
        }
        int ans = 0;
        vector<vector<int>> to(n + 1, vector<int>(k + 1, n));
        map<int, vector<int>> mp;
        vector<int> st(k + 1, n);
        for (int i = n - 1; i >= 0; i--) {
            if (!mp[a[i]].empty()) {
                st.emplace_back(mp[a[i]].back());
                sort(st.begin(), st.end());
                st.pop_back();
            }
            mp[a[i]].emplace_back(i);
            for (int j = 0; j <= k; j++) {
                to[i][j] = st[j];
            }
            debug(st);
        }
        debug(a);
        debug(to);
        vector<int> dp(k + 1);
        while (dp[k] < n) {
            ans++;
            for (int i = k; i >= 0; i--) {
                for (int l = k; l >= i; l--) {
                    dp[l] = max(dp[l], to[dp[i]][l - i]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}