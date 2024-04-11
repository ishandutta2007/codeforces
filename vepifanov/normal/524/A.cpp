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
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

int n;
int m;
int o;
vii w;
int g[200][200];
int name[200];
map<int, int> num;

int get (int x) {
    if (num.count (x)) re num[x];
    num[x] = o;
    name[o] = x;
    w.pb (mp (x, o));
    o++;
    re o - 1;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        a = get (a);
        b = get (b);
        g[a][b] = g[b][a] = 1;
    }
    sort (all (w));
    for (int I = 0; I < o; I++) {
        int i = w[I].se;
        vi v;
        int all = 0;
        for (int j = 0; j < o; j++)
            all += g[i][j];
        for (int j = 0; j < o; j++)
            if (!g[i][j] && i != j) {
                int cnt = 0;
                for (int k = 0; k < o; k++)
                    if (k != i && k != j)
                        cnt += g[i][k] & g[k][j];
                if (cnt * 100 >= m * all) v.pb (name[j]);
            }
        sort (all (v));
        printf ("%d: %d", w[I].fi, sz (v));
        for (int j = 0; j < sz (v); j++)
            printf (" %d", v[j]);
        printf ("\n");
    }
    return 0;
}