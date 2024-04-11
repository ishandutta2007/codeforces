#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
int main() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>> tab(n + 1, vector<int>(20, -1));
    vector<vector<long long>> dp(n + 1, vector<long long>(20));
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        if (i) pref[i] = pref[i - 1];
        pref[i] += (2 * (s[i] == '(') - 1);
    }
    vector<int> lst(2 * n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') {
            lst[pref[i] + n] = i;
            continue;
        }
        int look = pref[i];
        look -= (2 * (s[i] == '(') - 1);
        tab[i][0] = lst[look + n];
        lst[pref[i] + n] = i;
    }
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (tab[i][j - 1] == -1) continue;
            tab[i][j] = tab[ tab[i][j - 1] + 1][j - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; (1 << j) < n; j++) {
            if (tab[i][j] == -1) continue;
            if (j == 0) {
                dp[i][j] = 1;
                int st = i + 1;
                if (s[st] == ')') continue;
                int accum = 0;
                for (int b = 19; b >= 0; b--) {
                    if (tab[st][b] == -1
                            || tab[st][b] > tab[i][j]) continue;
                    dp[i][j] += dp[st][b];
                    dp[i][j] += accum * 1LL * (1 << b);
                    accum += (1 << b);
                    st = tab[st][b] + 1;
                }
            } else {
                dp[i][j] = dp[i][j - 1]
                    + dp[ tab[i][j - 1] + 1][j - 1]
                    + (1 << (j - 1)) * 1LL * (1 << (j - 1));
            }
        }
    }
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        --l, --r;
        int st = l;
        int accum = 0;
        long long ans = 0LL;
        for (int b = 19; b >= 0; b--) {
            if (tab[st][b] == -1 || tab[st][b] > r) continue;
            ans += dp[st][b];
            ans += accum * 1LL * (1 << b);
            accum += (1 << b);
            st = tab[st][b] + 1;
        }
        cout << ans << "\n";
    }
}