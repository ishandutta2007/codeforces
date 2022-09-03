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
int m;
int was[100000];
int was2[100000];
int p[100000];
int q[100000];
int cnt[100000];
vii v[100000];
int last[100000];
pair<ii, ii> w[100000];
int ct;
vi cur;
ll res[100000];

int go (int x) {
    was[x] = ct;
    cnt[x] = q[x];
    for (int i = 0; i < sz (v[x]); i++)
        if (was[v[x][i].fi] != ct)
            cnt[x] += go (v[x][i].fi);
    re cnt[x];
}

int go2 (int x, int all) {
    was2[x] = ct;
    for (int i = 0; i < sz (v[x]); i++)
        if (was2[v[x][i].fi] != ct) {
            res[v[x][i].se] = (ll)cnt[v[x][i].fi] * (all - cnt[v[x][i].fi]);
            go2 (v[x][i].fi, all);
        }   
    re 0;
}

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        scanf ("%d%d%d", &w[i].se.fi, &w[i].se.se, &w[i].fi.fi); w[i].se.se--; w[i].se.fi--;
        w[i].fi.se = i;
    }   
    for (int i = 0; i < n; i++) {
        p[i] = i;
        q[i] = 1;
    }
    sort (w, w + n - 1);
    for (int i = 0; i + 1 < n; ) {
        int j = i;
        ct++;
        cur.clear ();
        while (j + 1 < n && w[j].fi.fi == w[i].fi.fi) {
            int a = gp (w[j].se.fi);
            int b = gp (w[j].se.se);
            if (last[a] != ct) { last[a] = ct; v[a].clear (); cur.pb (a); }
            if (last[b] != ct) { last[b] = ct; v[b].clear (); cur.pb (b); }
            v[a].pb (mp (b, w[j].fi.se));
            v[b].pb (mp (a, w[j].fi.se));
            j++;
        }
        for (int j = 0; j < sz (cur); j++)
            if (was[cur[j]] != ct) {
                int all = go (cur[j]);
                go2 (cur[j], all);
            }
        j = i;
        while (j + 1 < n && w[j].fi.fi == w[i].fi.fi) {
            int a = gp (w[j].se.fi);
            int b = gp (w[j].se.se);
            if (rand () & 1) {
                p[a] = b;
                q[b] += q[a];
            } else {
                p[b] = a;
                q[a] += q[b];
            }
            j++;
        }
        i = j;
    }
    ll res = 0;
    for (int i = 0; i + 1 < n; i++) res = max (res, ::res[i]);
    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
        if (::res[i] == res)
            ans++;
    printf ("%I64d %d\n", res * 2, ans);
    for (int i = 0; i + 1 < n; i++)
        if (::res[i] == res)
            printf ("%d ", i + 1);
    printf ("\n");
    return 0;
}