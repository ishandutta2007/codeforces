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

int n;
int m, k;

ll res[51][51][102];
int was[51][51][102];
int use[51][51][102];
int prev[51][51][102];
ll a[51], b[51];
int c[51];
int p[51];

bool l1 (int i, int j) {
    re c[i] < c[j];
}

ll go (int I, int j, ll x) {
    if (I == m) re int (j != n) * (-1e18);
    int i = p[I];
    if (x < a[i] || x > b[i]) re -1e18;
    if (was[I][j][x - a[i]]) re res[I][j][x - a[i]];
    was[I][j][x - a[i]] = 1;
    ll cur = -1e18;
    int u = 0, p = 0;
    for (int t = I + 1; t <= m; t++) {
        if (c[::p[t]] <= c[i]) continue;
        ll t1 = go (t, j + 1, x + k) + x, t2 = go (t, j + 1, x * k) + x;
        if (t1 > cur) {
            cur = t1;
            u = 0;
            p = t;
        }
        if (t2 > cur) {
            cur = t2;
            u = 1;
            p = t;
        }
    }
    res[I][j][x - a[i]] = cur;
    use[I][j][x - a[i]] = u;
    prev[I][j][x - a[i]] = p;
    re res[I][j][x - a[i]];
}

int out (int I, int j, ll x) {
    if (I == m) re 0;
    cout << p[I] + 1 << " " << x << endl;
    if (use[I][j][x - a[p[I]]]) out (prev[I][j][x - a[p[I]]], j + 1, x * k); else out (prev[I][j][x - a[p[I]]], j + 1, x + k);
    re 0;
}

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        p[i] = i;
    }
    p[m] = m;
    c[m] = 101;
    sort (p, p + m, l1);
    memset (was, 0, sizeof (was));
    ll ans = -1e18, res = 0;
    int pos = 0;
    for (int j = 0; j < m; j++)
        for (ll i = a[p[j]]; i <= b[p[j]]; i++) {
            ll cur = go (j, 0, i);
            if (cur > ans) {
                ans = cur;
                res = i;
                pos = j;
            }
        }   
    if (ans < 0) printf ("NO\n"); else {
        printf ("YES\n");
        out (pos, 0, res);
    }
    return 0;
}