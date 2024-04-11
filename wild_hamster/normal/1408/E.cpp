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
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3, l;
ll a[2005005], b[2005000];
vector<ll> g[100500];

struct DSU {
    DSU() {}

    DSU(int N) {
        color.resize(N);
        siz.resize(N);
        for (int i = 0; i < N; i++) {
            color[i] = i;
            siz[i] = 1;
        }
    }

    int get(int v) {
        return (v == color[v]) ? v : (color[v] = get(color[v]));
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (siz[a] > siz[b]) {
            swap(a, b);
        }
        if (a != b) {
            color[a] = b;
            siz[b] += siz[a];
        }
    }

    int size(int x) {
        return siz[x];
    }

    vector<int> color;
    vector<int> siz;
};
DSU dsu(200500);

vector<pair<ll, pii> > f;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            ll y;
            cin >> y;
            y--;
            f.push_back(mp(b[y] + a[i], mp(y + n, i)));
        }
    }
    sort(f.rbegin(), f.rend());
    ll ans = 0;
    for (auto p : f) {
        ll x = p.Y.X;
        ll y = p.Y.Y;
        if (dsu.get(x) != dsu.get(y)) {
            dsu.unite(x, y);
        } else {
            ans += p.X;
        }

    }
    cout << ans << "\n";


    return 0;
}