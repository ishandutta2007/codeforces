#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll f[maxn], z;
array<ll, 2> mx;
vector<ll> rs;
string s;

void reset() {
    ll i;
    k = 0; mx = {-INF, -INF}; rs.clear(); flag[0] = 0;
    for (i = 1; i <= 26; i++) f[i] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> s; n = s.size(); s = '#' + s;
        reset();

        for (i = 1; i <= n; i++) {
            m = (ll)s[i] - 'a' + 1;
            if (f[m] == 0) k++;
            f[m]++; mx = max(mx, {-m, f[m]});
        }
        mx[0] *= -1; swap(mx[0], mx[1]);

        for (i = 1; i <= 26; i++) {
            if (f[i] == 1) flag[0] = 1;
        }

        if (flag[0] == 1) {
            for (i = 1; i <= 26; i++) {
                if (f[i] == 1) {
                    rs.pb(i); f[i]--; break;
                }
            }
            for (i = 2; i <= n; i++) {
                for (j = 1; j <= 26; j++) {
                    if (f[j] >= 1) {
                        rs.pb(j); f[j]--; break;
                    }
                }
            }
        } else if (k == 1 || k == n) {
            for (i = 1; i <= 26; i++) {
                for (j = 1; j <= f[i]; j++) {
                    rs.pb(i);
                }
            }
        } else if (mx[0] <= n / 2 + 1) {
            for (i = 1; i <= 2; i++) {
                rs.pb(mx[1]); f[mx[1]]--;
            }
            for (i = 3; i <= n; i++) {
                if (rs.back() != mx[1] && f[mx[1]] != 0) {
                    rs.pb(mx[1]); f[mx[1]]--;
                } else {
                    for (j = mx[1] + 1; j <= 26; j++) {
                        if (f[j] >= 1) {
                            rs.pb(j); f[j]--; break;
                        }
                    }
                }
            }
        } else if (k == 2) {
            rs.pb(mx[1]); f[mx[1]]--;
            for (i = mx[1] + 1; i <= 26; i++) {
                if (f[i] >= 1) {
                    for (j = 1; j <= f[i]; j++) rs.pb(i);
                    break;
                }
            }
            for (i = 1; i <= f[mx[1]]; i++) rs.pb(mx[1]);
        } else {
            rs.pb(mx[1]); f[mx[1]]--;
            for (i = mx[1] + 1; i <= 26; i++) {
                if (f[i] >= 1) {
                    rs.pb(i); f[i]--; z = i; break;
                }
            }
            for (i = 1; i <= f[mx[1]]; i++) rs.pb(mx[1]);
            for (i = z + 1; i <= 26; i++) {
                if (f[i] >= 1) {
                    rs.pb(i); f[i]--; break;
                }
            }
            for (i = mx[0] + 3; i <= n; i++) {
                for (j = mx[1] + 1; j <= 26; j++) {
                    if (f[j] >= 1) {
                        rs.pb(j); f[j]--; break;
                    }
                }
            }
        }

        for (auto u : rs) cout << (char)('a' + u - 1);
        cout << nl;
    }

    return 0;
}