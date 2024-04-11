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

int g[100][100];
int r[100];
int c[100];
int ar[100];
int ac[100];
vi v;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf ("%d", &g[i][j]);
            r[i] += g[i][j];
            c[j] += g[i][j];
        }
    while (true) {
        int ok = 1;
        for (int i = 0; i < n; i++)
            if (r[i] < 0) {
                ar[i] ^= 1;
                for (int j = 0; j < m; j++) {
                    c[j] -= g[i][j] * 2;
                    g[i][j] = -g[i][j];
                }
                r[i] = -r[i];
                ok = 0;
            }
        for (int j = 0; j < m; j++)
            if (c[j] < 0) {
                ac[j] ^= 1;
                for (int i = 0; i < n; i++) {
                    r[i] -= g[i][j] * 2;
                    g[i][j] = -g[i][j];
                }
                c[j] = -c[j];
                ok = 0;
            }
        if (ok) break;
    }
    for (int i = 0; i < n; i++)
        if (ar[i])
            v.pb (i + 1);
    printf ("%d", sz (v));
    for (int i = 0; i < sz (v); i++)
        printf (" %d", v[i]);
    printf ("\n");  
    v.clear ();
    for (int i = 0; i < m; i++)
        if (ac[i])
            v.pb (i + 1);
    printf ("%d", sz (v));
    for (int i = 0; i < sz (v); i++)
        printf (" %d", v[i]);
    printf ("\n");  
    return 0;
}