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
int p[200];
int was[200];
vii res;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = -1;
    int k = 0;
    for (int i = 0; i < m; i++) {
        int t;
        scanf ("%d", &t);
        for (int j = 0; j < t; j++) {
            int x;
            scanf ("%d", &x); x--;
            p[x] = k++;
                }
    }
    int f = 0;
    for (int i = 0; i < n; i++)
        if (p[i] == -1)
            f = i;
    memset (was, 0, sizeof (was));  
    for (int i = k; i < n; i++)
        if (p[i] != -1) {
            vi v;
            int j = i;
            while (j != -1) {
                was[j] = 1;
                v.pb (j);
                j = p[j];
            }
            for (int t = sz (v) - 2; t >= 0; t--) {
                res.pb (mp (v[t], v[t + 1]));
                if (v[t + 1] == f) f = v[t];
            }
        }
    for (int i = 0; i < k; i++)
        if (!was[i] && p[i] != -1 && p[i] != i) {
            vi v;
            int j = i;
            do {
                was[j] = 1;
                v.pb (j);
                j = p[j];
            } while (j != i);
            int of = f;
            res.pb (mp (v[sz (v) - 1], f));
            f = v[sz (v) - 1];
            for (int t = sz (v) - 2; t >= 0; t--) {
                res.pb (mp (v[t], v[t + 1]));
                if (v[t + 1] == f) f = v[t];
            }
            res.pb (mp (of, v[0]));
            f = of;
        }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi + 1, res[i].se + 1);
    return 0;
}