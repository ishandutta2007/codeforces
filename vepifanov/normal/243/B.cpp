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
int h, t;
vi v[100000];
int ea[200000];
int eb[200000];
int use[100000];

int can (int a, int b, int d) {
    int c = 0, i = 0, j = 0;
    while (c < d && (i < sz (v[a]) || j < sz (v[b])))
        if (i < sz (v[a]) && (j == sz (v[b]) || v[a][i] < v[b][j])) { c += int (v[a][i] != b); i++; } else
        if (j < sz (v[b]) && (i == sz (v[a]) || v[a][i] > v[b][j])) { c += int (v[b][j] != a); j++; } else {
            c++;
            i++;
            j++;
        }
    re int (c >= d);
}

int main () {
    scanf ("%d%d%d%d", &n, &m, &h, &t);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
        ea[i] = a;
        eb[i] = b;
        ea[i + m] = b;
        eb[i + m] = a;
    }
    for (int i = 0; i < n; i++) sort (all (v[i]));
    for (int i = 0; i < 2 * m; i++) {
        int a = ea[i];
        int b = eb[i];
        if (sz (v[a]) >= h + 1 && sz (v[b]) >= t + 1 && can (a, b, h + t)) {
            printf ("YES\n");
            printf ("%d %d\n", a + 1, b + 1);
            for (int j = 0; j < sz (v[b]); j++)
                use[v[b][j]] = 1;
            use[a] = use[b] = 2;
            vi x, y;
            for (int j = 0; j < sz (v[a]) && sz (x) < h; j++)
                if (!use[v[a][j]]) {
                    x.pb (v[a][j]);
                    use[v[a][j]] = 2;
                }   
            for (int j = 0; j < sz (v[a]) && sz (x) < h; j++)
                if (use[v[a][j]] == 1) {
                    x.pb (v[a][j]);
                    use[v[a][j]] = 2;
                }   
            for (int j = 0; j < sz (v[b]) && sz (y) < t; j++)
                if (use[v[b][j]] != 2) {
                    y.pb (v[b][j]);
                    use[v[b][j]] = 2;
                }   
            sort (all (x));
            sort (all (y));
            for (int j = 0; j < h; j++) printf ("%d ", x[j] + 1);
            printf ("\n");
            for (int j = 0; j < t; j++) printf ("%d ", y[j] + 1);
            printf ("\n");
            re 0;
        }
    }
    printf ("NO\n");
    return 0;
}