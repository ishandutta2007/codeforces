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
#define MOD 998244353
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3, l;
ll a[2005005], b[2005000];
vector<ll> g[300500];
ll cur_edge = 0;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    a[0] = b[0] = 1;
    for (int i = 1; i < 300500; i++) {
        a[i] = a[i-1] * 2 % MOD;
        b[i] = b[i-1] * 3 % MOD;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'o') {
                g[i].push_back(1);
                l++;
            } else {
                g[i].push_back(0);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll t = 0;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                t += 1;
            } else {
                if (t > 1) {
                    ans = (ans + a[l - t] *((3*(t-1)+1)*a[t-1] % MOD - ((t-1) % 2 == 0 ? 1 : -1)) % MOD * 443664157LL) % MOD;
                }
                t = 0;
            }

        }

        if (t > 1) {
            ans = (ans + a[l - t] *((3*(t-1)+1)*a[t-1] % MOD - ((t-1) % 2 == 0 ? 1 : -1)) % MOD * 443664157LL) % MOD;
        }
        t = 0;
    }

    for (int i = 0; i < m; i++) {
        ll t = 0;
        for (int j = 0; j < n; j++) {
            if (g[j][i] == 1) {
                t += 1;
            } else {
                if (t > 1) {
                    ans = (ans + a[l - t] *((3*(t-1)+1)*a[t-1] % MOD - ((t-1) % 2 == 0 ? 1 : -1)) % MOD * 443664157LL) % MOD;
                }
                t = 0;
            }

        }

        if (t > 1) {
            ans = (ans + a[l - t] *((3*(t-1)+1)*a[t-1] % MOD - ((t-1) % 2 == 0 ? 1 : -1)) % MOD * 443664157LL) % MOD;
        }
        t = 0;
    }
    cout << ans << "\n";
    return 0;
}