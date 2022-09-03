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


int n;
int m, S, T;
int mark[1000], d[1000];
ll D[1000];
vii v[1000], w[1000];
set<ii> all;

int main() {
        scanf ("%d%d", &n, &m);
        scanf ("%d%d", &S, &T); S--; T--;
        for (int i = 0; i < m; i++) {
                int a, b, c;
                scanf ("%d%d%d", &a, &b, &c); a--; b--;
                v[a].pb (mp (b, c));
                v[b].pb (mp (a, c));
        }
        for (int i = 0; i < n; i++) {
                int t, c;
                scanf ("%d%d", &t, &c);
                memset (mark, 0, sizeof (mark));
                for (int j = 0; j < n; j++) d[j] = t + 1;
                d[i] = 0;
                mark[i] = 1;
                all.insert (mp (0, i));
                while (!all.empty ()) {
                        int j = all.begin ()->se;
                        all.erase (all.begin ());
                        mark[j] = 2;
                        for (int k = 0; k < sz (v[j]); k++) {
                                int nj = v[j][k].fi;
                                int nd = d[j] + v[j][k].se;
                                if (d[nj] > nd) {
                                        if (mark[nj]) all.erase (mp (d[nj], nj));
                                        mark[nj] = 1;
                                        d[nj] = nd;
                                        all.insert (mp (nd, nj));
                                }
                        }
                }
                for (int j = 0; j < n; j++)
                        if (j != i && d[j] <= t)
                                w[i].pb (mp (j, c));
        }
        memset (mark, 0, sizeof (mark));
        for (int j = 0; j < n; j++) D[j] = 1e18;
        D[S] = 0;
        mark[S] = 1;
        for (int i = 0; i < n; i++) {
                int k = -1;
                for (int j = 0; j < n; j++)
                        if (mark[j] == 1 && (k == -1 || D[k] > D[j]))
                                k = j;
                if (k == -1) break;
                if (k == T) {
                        printf ("%I64d\n", D[k]);
                        re 0;
                }
                mark[k] = 2;
                for (int j = 0; j < sz (w[k]); j++) {
                        int nk = w[k][j].fi;
                        ll nd = D[k] + w[k][j].se;
                        if (D[nk] > nd) {
                                D[nk] = nd;
                                mark[nk] = 1;
                        }
                }
        }
        printf ("-1\n");
        return 0;
}