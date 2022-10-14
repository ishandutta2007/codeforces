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
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[3000500], c[300050], d[300500];
vector<ll> f;
vector<ll> hyu;
vector<pii> g[300500];
void solve() {
    ll n, m;
    scanf("%d %d", &n, &m);
    n *= 3;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        a[i] = 0;
        d[i] = 0;
    }
    hyu.clear();
    f.clear();
    for (int i = 0; i < m; i++) {
        ll x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(mp(y, i+1));
        g[y].push_back(mp(x, i+1));
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            continue;
        }
        ll flag = 0;
        for (auto v : g[i]) {
            if (d[v.X] == 0) {
                f.push_back(v.Y);
                d[v.X] = 1;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            hyu.push_back(i);
        }
        d[i] = 1;
    }
    if (hyu.size() >= n/3) {
        printf("IndSet\n");
        for (int i = 0; i < n/3; i++) {
            printf("%d ", hyu[i]);
        }
        printf("\n");
    } else if (f.size() >= n/3) {
        printf("Matching\n");
        for (int i = 0; i < n/3; i++) {
            printf("%d ", f[i]);
        }
        printf("\n");
    } else {
        cout << "HYU" << endl;
        cout << 1488 / 0 << endl;
    }
}
int main() {
    ll t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;

}