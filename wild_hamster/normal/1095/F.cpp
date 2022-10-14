#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD ((1<<30)-1)
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  a[1500050], b[505000], p[500500], dp[500500], ans;

set<pii> g;
ll Abs(ll x) {
    return x>0?x:-x;
}

int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int aa, int b) {
    aa = dsu_get (aa);
    b = dsu_get (b);
    if (rand() & 1)
        swap (aa, b);
    if (aa != b) {
        p[aa] = b;
        g.erase(mp(a[aa], aa));
        g.erase(mp(a[b], b));
        a[b] = min(a[b], a[aa]);
        g.insert(mp(a[b], b));
    }
}

string s[305];
pair<ll, pii> f[500500];
int main() {
    srand(time(0));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        p[i] = i;
        g.insert(mp(a[i], i));
    }
    for (int i = 0; i < m; i++) {
        scanf("%I64d %I64d %I64d", &f[i].Y.X, &f[i].Y.Y, &f[i].X);
    }
    sort(f, f+m);
    ll ans = 0;
    for (int i=0; i<m; ++i) {
        ll aa = f[i].second.first,  b = f[i].second.second,  l = f[i].first;
        while (l > (*(g.begin())).X + (*(next(g.begin()))).X) {
            ll ab =(*(g.begin())).Y;
            ll ba = (*(next(g.begin()))).Y;
            ans += a[ab] + a[ba];
            dsu_unite(ab, ba);
            if (g.size() == 1)
                break;
        }


        if (g.size() == 1) {
            break;
        }

        if (dsu_get(aa) != dsu_get(b)) {
            dsu_unite (aa, b);
            ans += l;
        }

        if (g.size() == 1) {
            break;
        }
    }

    while (g.size() > 1) {
        ll ab =(*(g.begin())).Y;
        ll ba = (*(next(g.begin()))).Y;
        ans += a[ab] + a[ba];
        dsu_unite(ab, ba);
    }
    cout << ans << endl;
    return 0;
}