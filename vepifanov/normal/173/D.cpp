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

vi v[100000];
set<ii> all;
int was[100000], res[100000];
vi w[2];

int go (int x, int y) {
    was[x] = 1;
    w[y].pb (x);
    for (int i = 0; i < sz (v[x]); i++)
        if (!was[v[x][i]])
            go (v[x][i], y ^ 1);
    re 0;
}

int make () {
    int r = 1, rem = 3;
    for (int i = 0; i < sz (w[0]); i++)
        if (!res[w[0][i]]) {
            res[w[0][i]] = r;
            rem--;
            if (!rem) { r++; rem = 3; }
        }
    for (int i = 0; i < sz (w[1]); i++)
        if (!res[w[1][i]]) {
            res[w[1][i]] = r;
            rem--;
            if (!rem) { r++; rem = 3; }
        }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
        all.insert (mp (a, b));
        all.insert (mp (b, a));
    }
    for (int i = 0; i < n; i++)
        if (!was[i])
            go (i, 0);
    int ok = 0;
    if (sz (w[0]) % 3 == 0) {
        ok = 1;
        make ();
        } else {
            if (sz (w[0]) % 3 == 2) swap (w[0], w[1]);
            int a = -1;
            for (int i = 0; i < sz (w[0]); i++)
                if (sz (v[w[0][i]]) + 2 <= sz (w[1])) {
                    a = w[0][i];
                    break;  
                }
        if (a >= 0) {
            int b = -1, c = -1;
            for (int j = 0; j < sz (w[1]); j++)
                if (!all.count (mp (a, w[1][j])))
                    if (b == -1) b = w[1][j]; else {
                        c = w[1][j];
                        break;
                    }
            res[a] = res[b] = res[c] = n / 3;
            make ();
            ok = 1;
        } else {
            int b = -1;
            for (int j = 0; j < sz (w[1]); j++)
                if (sz (v[w[1][j]]) + 2 <= sz (w[0]))
                    if (a == -1) a = w[1][j]; else {
                        b = w[1][j];
                        break;
                    }
            if (b != -1) {
                int c = -1, d = -1;
                for (int j = 0; j < sz (w[0]); j++)
                    if (!all.count (mp (a, w[0][j])))
                        if (c == -1) c = w[0][j]; else {
                            d = w[0][j];
                            break;
                        }
                res[a] = res[c] = res[d] = n / 3;
                c = d = -1;
                for (int j = 0; j < sz (w[0]); j++)
                    if (!all.count (mp (b, w[0][j])))
                        if (c == -1) c = w[0][j]; else {
                            d = w[0][j];
                            break;
                        }
                    res[b] = res[c] = res[d] = n / 3 - 1;
                    make ();
                    ok = 1;
                }   
        }
    }
    if (!ok) printf ("NO\n"); else {
        printf ("YES\n");
        for (int i = 0; i < n; i++) printf ("%d ", res[i]);
        printf ("\n");
    }
    return 0;
}