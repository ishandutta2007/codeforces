#include <bits/stdc++.h>

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
#define prev PREV
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

#define filename ""

const int N = 500000;

int n;
int m;
int cnt[N];
ll res[N];
ll same[N];
int nu[N];
int nv[N];
int no[N];
vi full[N];
vi empty[N];
int was[N];
int last[N];
int ucnt[N];
int ct;
vi uall[N];
//int nowempty[N];

int go (int *p, int x) {
    if (x != p[x]) p[x] = go (p, p[x]);
    re p[x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        ucnt[i] = 1;
//        vcnt[i] = 1;
        empty[i].pb (i);
        uall[i].pb (i);
  //      vall[i].pb (i);
        nu[i] = i;
        nv[i] = i;
        no[i] = i;
//        nowempty[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        char h[5];
        scanf (" %s", h);
        if (h[0] == 'U') {
            int a, b;
            scanf ("%d%d", &a, &b); a--; b--;
            a = go (nu, a);
            b = go (nu, b);
            if (a == b) continue;
            if (ucnt[a] < ucnt[b]) swap (a, b);
            nu[b] = a;
            ucnt[a] += ucnt[b];
            for (int j = 0; j < sz (uall[b]); j++) {
                int x = uall[b][j];
                uall[a].pb (x);
                res[x] = res[x] + same[b] - same[a];
            }
            for (int j = 0; j < sz (empty[b]); j++) {
                int x = empty[b][j];
                empty[a].pb (x);
//                printf ("add empty %d\n", x);
            }
        } else
        if (h[0] == 'M') {
            int a, b;
            scanf ("%d%d", &a, &b); a--; b--;
            a = go (nv, a);
            b = go (nv, b);
            if (a == b) continue;
            if (sz (full[a]) < sz (full[b])) swap (a, b);
            nv[b] = a;
//            vcnt[a] += vcnt[b];
/*            for (int j = 0; j < sz (vall[b]); j++) {
                int x = vall[b][j];
                vall[a].pb (x);
            }*/
            for (int j = 0; j < sz (full[b]); j++) {
                int x = full[b][j];
                full[a].pb (x);
            }
        } else
        if (h[0] == 'A') {
            int a;
            scanf ("%d", &a); a--;
            a = go (nu, a);
            for (int i = 0; i < sz (empty[a]); i++) {
                int x = empty[a][i];
                res[x] = -same[a];
//                nowempty[x] = 0;
                int b = go (nv, x);
                full[b].pb (x);
            }
            same[a] += ucnt[a];
            empty[a].clear ();
        } else
        if (h[0] == 'Z') {
            int a;
            scanf ("%d", &a); a--;
            a = go (nv, a);
            ct++;
            for (int i = 0; i < sz (full[a]); i++) {
                int x = full[a][i];
                int b = go (nu, x);
                if (was[b] == ct) no[x] = last[b]; else {
//                  nowempty[x] = 1;
                    res[x] = -same[b];
                    empty[b].pb (x);
                    was[b] = ct;
                    last[b] = x;
                }
            }
            full[a].clear ();
        } else
        if (h[0] == 'Q') {
            int a;
            scanf ("%d", &a); a--;
            a = go (no, a);
            int b = go (nu, a);
//            cout << nowempty[a] ? 0 : res[a] + same[b] << "\n";
            cout << res[a] + same[b] << "\n";
        }
//      for (int j = 0; j < n; j++) printf ("%I64d ", res[j] + same[go (nu, j)]);
//      printf ("\n");
    }
    re 0;
}