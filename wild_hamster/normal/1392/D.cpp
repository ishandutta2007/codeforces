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
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[1000500], b[1005000], dp[1000500][2], used[1005000], dpp[1005000];
set<pii> f;
ll diff(string x, string y) {
    ll ans = 0;
    for (int i = 0; i < x.size(); i++) {
        ans += (x[i] != y[i]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        string s;
        cin >> n;
        cin >> s;
        s.append(s);
        for (int i = 0; i < n; i++) {
            used[i] = 0;
        }
        ll sum = 0;


        ll ans = MOD;
        for (int j = 0; j < 10; j++) {
            string t;
            t.push_back(s.back());
            for (int i = 0; i + 1 < s.size(); i++) {
                t.push_back(s[i]);
            }
            s = t;
            for (int i = 0; i <= n + 3; i++) {
                dp[i][0] = dp[i][1] = MOD;
            }
            dp[0][0] = 0;
            for (int i = 0; i < n + 3; i++) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + diff("R", s.substr(i, 1)));
                dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + diff("RR", s.substr(i, 2)));

                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + diff("L", s.substr(i, 1)));
                dp[i + 2][0] = min(dp[i + 2][0], dp[i][1] + diff("LL", s.substr(i, 2)));
            }
            ans = min(ans, dp[n][0]);
        }
        cout << ans << "\n";
    }
    return 0;
}