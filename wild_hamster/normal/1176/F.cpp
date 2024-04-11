#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[500500], c[100500];
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}
ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll mulg(ll x, ll y) {
    return x * y % MOD;
}

void add(ll& x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}
ll dp[200500][11];
vector<ll> g[5];
ll dpr[4]; //amount of cards, wasted
pii tmp[4];
ll pos;
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 10; j++) {
            dp[i][j] = -(ll)1e+18;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++) {
            g[j].clear();
        }
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
        }
        vector<pii> pool;
        for (int j = 1; j <= 3; j++) {
            sort(g[j].begin(), g[j].end());
            reverse(g[j].begin(), g[j].end());
            if (j == 1) {
                for (int k = 0; k < 3 && k < g[j].size(); k++) {
                    pool.push_back(mp(g[j][k], j));
                }
            } else {
                for (int k = 0; k < 1 && k < g[j].size(); k++) {
                    pool.push_back(mp(g[j][k], j));
                }
            }
        }
        //cout << pool.size() << endl;
        for (int j = 1; j <= 10; j++) {
            dpr[0] = 0;
            for (int k = 1; k <= 3; k++) {
                dpr[k] = -(ll)1e+18;
            }
            ll sz = pool.size();
            for (int i1 = 0; i1 < sz; i1++) {

                tmp[0] = pool[i1];
                pos = 1;
                for (int i2 = 0; i2 <= sz; i2++) {
                    if (i2 != sz && i2 != i1) {
                        tmp[pos++] = pool[i2];
                    }
                    for (int i3 = 0; i3 <= sz; i3++) {
                        if (i3 != sz && i3 != i2 && i3 != i1) {
                            tmp[pos++] = pool[i3];
                        }

                        ll cur_val = 0, cur_w = 0;
                        for (int k = 0; k < pos; k++) {
                            if (k + 1 == j) {
                                cur_val += 2 * tmp[k].X;
                            } else {
                                cur_val += tmp[k].X;
                            }
                            cur_w += tmp[k].Y;
                        }
                        if (cur_w <= 3) {
                            dpr[pos] = max(dpr[pos], cur_val);
                        }

                        if (i3 != sz && i3 != i2 && i3 != i1) {
                            pos--;
                        }
                    }
                    if (i2 != sz && i2 != i1) {
                        pos--;
                    }
                }
            }
            for (int k = 0; k <= 3; k++) {
                ll cur = dpr[k];
                dp[i+1][(10-j+k) % 10] = max(dp[i+1][(10-j+k) % 10], dp[i][10-j] + cur);
            }
        }
        /*for (int j = 0; j < 10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;*/
    }
    ll ans = 0;
    /*for (int j = 0; j < 10; j++) {
        cout << dp[n][j] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < 10; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}