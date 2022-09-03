#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
        re x > 0 ? x : -x;
}

const int INF = 2e9;

int n;
int m;
int x, y, p, r;
int tree[1000000];
pair<pair<ll, int>, pair<int, ll> > v[250000];
pair<int, ll> q[250001];
int o;

int add (int x, int l, int r, int p, int q) {
        if (r < p || l > p) re tree[x];
        if (l == r) re tree[x] = q;
        int s = (l + r) / 2;
        re tree[x] = min (add (x * 2 + 1, l, s, p, q), add (x * 2 + 2, s + 1, r, p, q));
}

int upd (int x, int l, int r, int lc, int rc, int p) {
        if (tree[x] > p || r < lc || l > rc) re tree[x];
        if (l == r) {
                q[o++] = v[l].se;
                re tree[x] = INF;
        }
        int s = (l + r) / 2;
        re tree[x] = min (upd (x * 2 + 1, l, s, lc, rc, p), upd (x * 2 + 2, s + 1, r, lc, rc, p));
}

int main() {
        scanf ("%d%d%d%d%d", &x, &y, &p, &r, &n);
        for (int i = 0; i < n; i++) {
                int x, y, m, p, r;
                scanf ("%d%d%d%d%d", &x, &y, &m, &p, &r);
                v[i] = mp (mp ((ll)(x - ::x) * (x - ::x) + (ll)(y - ::y) * (y - ::y), m), mp (p, (ll)r * r));
        }
        sort (v, v + n);
        for (int i = 0; i < n; i++)
            add (0, 0, n - 1, i, v[i].fi.se);
        o = 1;
        q[0] = mp (p, (ll)r * r);
        for (int i = 0; i < o; i++) {
                int p = q[i].fi;
                ll r = q[i].se;
                int ll = -1, rr = n;
                while (rr - ll > 1) {
                        int ss = (ll + rr) / 2;
                        if (v[ss].fi.fi <= r) ll = ss; else rr = ss;
                }
                if (ll >= 0) upd (0, 0, n - 1, 0, ll, p);
        }
        printf ("%d\n", o - 1);
        return 0;
}