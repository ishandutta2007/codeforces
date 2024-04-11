
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 998244353
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<ll> g[200500];
ll w[200500], lv[200500];
ll dp[3005][3005];
ll d[3005];
vector<ll> a, b, c;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    string t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    n = s.size();
    m = t.size();
    ll ans = 0;
    /*dp[0][0] = 1;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]);
                if (dp[i+1][j+1] >= MOD) {
                    dp[i+1][j+1] -= MOD;
                }
            }
            dp[i+1][j] += dp[i][j];
            if (dp[i+1][j] >= MOD) {
                dp[i+1][j] -= MOD;
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    cout << ans << "\n";

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    ll m = t.size();
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + m);*/
    for (int i = 0; i < n - m + 1; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int l = 0; l <= i; l++) {
            int r = l + (n - 1 - i);
            if (l >= m || s[i] == t[l]) {
                dp[i+1][l+1] += dp[i][l];
                if (dp[i+1][l+1] >= MOD) {
                    dp[i+1][l+1] -= MOD;
                }
            }

            if (r >= m || s[i] == t[r]) {
                dp[i+1][l] += dp[i][l];
                if (dp[i+1][l] >= MOD) {
                    dp[i+1][l] -= MOD;
                }
            }
        }
    }
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i = 0; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << ans % MOD << "\n";
    return 0;
}