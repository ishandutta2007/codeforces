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

const int inf = 1000000000;

int n;
int m;
int p, q;
vii res;
int x[100000];
int y[100000];
set<ii> all;

int gp (int z) {
    if (x[z] != z) x[z] = gp (x[z]);
    re x[z];
}

int main () {
    scanf ("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 0; i < n; i++) {
        x[i] = i;
        y[i] = 0;
    }   
    int rem = n, la = -1, lb = -1;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        la = a;
        lb = b;
        a = gp (a);
        b = gp (b);
        if (a == b) y[a] = min (inf, y[a] + c); else {
            rem--;
            if (rand () & 1) swap (a, b);
            x[a] = b;
            y[b] = min (inf, min (inf, y[a] + y[b]) + c);
        }
    }   
    if (rem < q || rem - p > q || rem == n && q == n && p > 0) printf ("NO\n"); else {
        printf ("YES\n");
        if (rem == 1) {
            for (int i = 0; i < p; i++) printf ("%d %d\n", 1, 2);
            re 0;
        }
        for (int i = 0; i < n; i++)
            if (x[i] == i)
                all.insert (mp (y[i], i));
        while (rem > q) {
            p--;
            rem--;
            ii x = *all.begin ();
            all.erase (all.begin ());
            ii y = *all.begin ();
            all.erase (all.begin ());
            res.pb (mp (x.se, y.se));
            all.insert (mp (min ((ll)inf, (ll)2 * (x.fi + y.fi) + 1), x.se));
        }
        if (p > 0) {
            if (res.empty ()) {
                if (m == 0)
                    res.pb (mp (1, 2));
                else
                    res.pb (mp (la, lb));
                p--;
            }
            while (p > 0) {
                res.pb (res[sz (res) - 1]);
                p--;
            }
        }   
        for (int i = 0; i < sz (res); i++)
            printf ("%d %d\n", res[i].fi + 1, res[i].se + 1);
    }
    return 0;
}