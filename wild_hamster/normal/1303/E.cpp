#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[100500];
ll w[27][27];
vector<ll> g[27];
ll used[27];
vector<ll> comp;
ll dp[405][405], curdp[405];

bool can(string s, string x, string y) {
    ll p1 = x.size();
    ll p2 = y.size();
    ll n = s.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= p1; j++) {
            dp[i][j] = -MOD;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p1; j++) {
            curdp[j] = dp[i][j];
        }
        for (int j = 0; j <= p1; j++) {
            if (dp[i][j] < 0) {
                continue;
            }
            if (j < p1 && s[i] == x[j]) {
                curdp[j+1] = max(curdp[j+1], dp[i][j]);
            }
            if (dp[i][j] < p2 && s[i] == y[dp[i][j]]) {
                curdp[j] = max(curdp[j], dp[i][j] + 1);
            }
        }
        for (int j = 0; j <= p1; j++) {
            dp[i+1][j] = curdp[j];
        }
    }
    return dp[n][p1] == p2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s, s2;
        cin >> s;
        cin >> s2;
        ll hyu = 0;
        for (int i = 0; i <= s2.size(); i++) {
            string tt;
            for (int j = 0; j < i; j++) {
                tt.push_back(s2[j]);
            }
            string tt2;
            for (int j = i; j < s2.size(); j++) {
                tt2.push_back(s2[j]);
            }
            if (can(s, tt, tt2)) {
                hyu = 1;
                cout << "YES\n";
                break;
            }
        }
        if (!hyu) {
            cout << "NO\n";
        }
    }
    return 0;
}