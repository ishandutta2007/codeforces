#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 1228227
#define MOD 1000000007
ll n, x, k, z, m, pa, pb;
ll a[MAXN], b[MAXN], cp[MAXN];
vector<ll> g[MAXN], gr[MAXN];
ll get_num(ll x, ll y) {
    return x * m + y;
}

void put_edge(ll u, ll v) {
    if (a[u] == 0 && a[v] == 0) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }
}

void dfs(ll v, ll p) {
    b[v] |= p;
    if (p == 1) {
        for (auto to : g[v]) {
            if ((b[to] & p) != p) {
                dfs(to, p);
            }
        }
    } else {
        for (auto to : gr[v]) {
            if ((b[to] & p) != p) {
                dfs(to, p);
            }
        }
    }

}

ll f[MAXN];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            ll x = get_num(i, j);
            if (s[j] == '#') {
                a[x] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n) {
                put_edge(get_num(i, j), get_num(i+1, j));
            }
            if (j + 1 < m) {
                put_edge(get_num(i, j), get_num(i, j+1));
            }
        }
    }

    dfs(0, 1);
    dfs(n*m-1, 2);
    if (b[0] != 3) {
        cout << 0 << endl;
        return 0;
    }
    {
        ll x = 0, y = 0;
        while (mp(x, y) != mp(n -1, m - 1)) {
            ll t = get_num(x, y);
            if (t != 0 && t != n*m-1) {
                f[t] = 1;
            }
            if (x + 1 < n) {
                ll s = get_num(x + 1, y);
                if (b[s] == 3) {
                    x++;
                    continue;
                }
            }
            if (y + 1 < m) {
                ll s = get_num(x, y + 1);
                if (b[s] == 3) {
                    y++;
                    continue;
                }
            }
        }
    }

    {
        ll x = 0, y = 0;
        while (mp(x, y) != mp(n -1, m - 1)) {
            ll t = get_num(x, y);
            if (f[t] == 1) {
                cout << "1" << endl;
                return 0;
            }

            if (y + 1 < m) {
                ll s = get_num(x, y + 1);
                if (b[s] == 3) {
                    y++;
                    continue;
                }
            }

            if (x + 1 < n) {
                ll s = get_num(x + 1, y);
                if (b[s] == 3) {
                    x++;
                    continue;
                }
            }
        }
    }

    cout <<  2 << endl;




    return 0;
}