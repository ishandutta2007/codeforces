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

int n;
int m, r;
int p[300000], s[300000], f[300000], lkey[300000], rkey[300000];
double res[300000];
ll sum[300001];
int cnt[300001];
vi w[300000];
vector<pair<int, ii> > v;

int go (int x) {
    f[x] = int (sz (w[x]) == 0);
    for (int i = 0; i < sz (w[x]); i++)
        go (w[x][i]);
    re 0;
}

int add (int l, int r, int s) {
    sum[l] += s;
    sum[r + 1] -= s;
    cnt[l]++;
    cnt[r + 1]--;
    re 0;
}

int go2 (int x, int l, int r) {
    if (f[x]) re 0;
    int s = p[x];
    add (s + 1, r, lkey[s]);
    add (l, s - 1, rkey[s]);
    int a = w[x][0], b = w[x][1];
    if (::s[a] > ::s[b]) swap (a, b);
    go2 (a, l, s - 1);
    go2 (b, s + 1, r);
    re 0;
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &p[i], &s[i]); p[i]--;
        v.pb (mp (s[i], mp (0, i)));
        if (p[i] == -2) r = i; else w[p[i]].pb (i);
    }
    go (r);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf ("%d", &x);
        v.pb (mp (x, mp (1, i)));
    }   
    sort (all (v));
    int last = 0;
    for (int i = 0; i < sz (v); i++) {
        if (v[i].se.fi == 0 && f[v[i].se.se]) last = v[i].fi;
        lkey[i] = last;
    }
    last = 0;
    for (int i = sz (v) - 1; i >= 0; i--) {
        if (v[i].se.fi == 0 && f[v[i].se.se]) last = v[i].fi;
        rkey[i] = last;
    }
    for (int i = 0; i < sz (v); i++)
        if (v[i].se.fi == 0)
            p[v[i].se.se] = i;
    go2 (r, 0, sz (v) - 1);
    ll cur = 0;
    int cnt = 0;
    for (int i = 0; i < sz (v); i++) {
        cur += sum[i];
        cnt += ::cnt[i];
        if (v[i].se.fi == 1) res[v[i].se.se] = (cur + 0.0) / cnt;
    }
    for (int i = 0; i < m; i++) printf ("%.10f\n", res[i]);
    return 0;
}