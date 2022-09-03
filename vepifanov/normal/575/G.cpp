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

const int N = 100000;

int n;
int m;
int zero[N];
int was[N];
int prev[N];
int bd[N];
vii v[N];
int q[N];
int nq[N];
int d[N];
int o, no;

int go (int x) {
    int l = 0, r = 1;
    zero[x] = 1;
    q[0] = x;
    bd[0] = 0;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int z = v[x][i].se;
            if (z == 0 && !zero[y]) {
                bd[y] = bd[x] + 1;
                zero[y] = 1;
                q[r++] = y;
                prev[y] = x;
            }
        }
    }
    re 0;
}

int out (int x) {
    printf ("%d ", x);
    if (x == n - 1) re 0;
    out (prev[x]);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    go (n - 1);
    int l = 0, r = 1, len = 1e9;
    was[0] = 1;
    q[0] = 0;
    d[0] = 0;
    while (l < r) {
        int x = q[l++];
//      printf ("%d %d = %d\n", x, zero[x], d[x]);
        if (zero[x]) len = min (len, d[x]);
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            if (!was[y]) {
                was[y] = 1;
                d[y] = d[x] + 1;
                q[r++] = y;
            }
        }
    }
    o = 0;
    for (int i = 0; i < n; i++)
        if (zero[i] && was[i] && d[i] == len)
            q[o++] = i;
    memset (was, 0, sizeof (was));
    for (int i = len - 1; i >= 0; i--) {
        no = 0;
        int ne = 10;
        for (int j = 0; j < o; j++) {
            int x = q[j];
            for (int k = 0; k < sz (v[x]); k++) {
                int y = v[x][k].fi;
                int z = v[x][k].se;
                if (d[y] + 1 == d[x]) ne = min (ne, z);
            }
        }   
        for (int j = 0; j < o; j++) {
            int x = q[j];
            for (int k = 0; k < sz (v[x]); k++) {
                int y = v[x][k].fi;
                int z = v[x][k].se;
                if (d[y] + 1 == d[x] && z == ne) {
                    if (!was[y] || bd[y] > bd[x] + 1) {
                        bd[y] = bd[x] + 1;
                        prev[y] = x;
                    }
                    if (!was[y]) {
                        was[y] = 1;
                        nq[no++] = y;
                    }   
                }
            }
        }
        printf ("%d", ne);
        o = no;
        for (int j = 0; j < o; j++) q[j] = nq[j];
    }
    if (zero[0]) printf ("0");
    printf ("\n");
    printf ("%d\n", bd[0] + 1);
    out (0);
    re 0;
}