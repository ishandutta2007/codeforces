#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000000000 + 7;

int n;
int m;

int tree[1000000];
ii v[100000];
int res[100000];

int get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re (get (x * 2, l, s, lc, rc) + get (x * 2 + 1, s + 1, r, lc, rc)) % mod;
}

int add (int x, int l, int r, int p, int q) {
    if (r < p || l > p) re tree[x];
    if (l == r) re tree[x] = q;
    int s = (l + r) / 2;
    re tree[x] = (add (x * 2, l, s, p, q) + add (x * 2 + 1, s + 1, r, p, q)) % mod;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf ("%d%d", &v[i].se, &v[i].fi);
    sort (v, v + m);
    int ans = 0, cur = -1;

    for (int i = 0; i < m; i++) {
        int l = 0, r = i;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (v[s].fi >= v[i].se) r = s; else l = s;
        }
        if (v[l].fi < v[i].se) l++;
        if (l <= cur) res[i] = get (1, 0, m - 1, l, cur);
        if (v[i].se == 0) res[i] = (res[i] + 1) % mod;
        if (v[i].fi == n) ans = (ans + res[i]) % mod;
        add (1, 0, m - 1, i, res[i]);
        if (i + 1 < m && v[i].fi < v[i + 1].fi) cur = i;
    }
    printf ("%d\n", ans);
    return 0;
}