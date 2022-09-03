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

const int MAX = 10000000;

int n;
int m;
int p[700000];
vii v[2][700000];
int f[MAX + 1];
int r = 0;
int x[100000];
int y[100000];

int add (int x, int q, int i) {
    for (int j = 0; p[j] * p[j] <= x; j++)
        if (x % p[j] == 0) {
            int k = 0;
            while (x % p[j] == 0) {
                x /= p[j];
                k++;
            }
            v[q][j].pb (mp (i, k));
        }   
    if (x > 1) v[q][f[x]].pb (mp (i, 1));
    re 0;
}

int main () {
    for (int i = 2; i <= MAX; i++)
        if (!f[i]) {
            f[i] = r;
            p[r++] = i;
            if (i <= MAX / i)
                for (int j = i * i; j <= MAX; j += i)
                    f[j] = 1;
        }
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        add (x[i], 0, i);
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d", &y[i]);
        add (y[i], 1, i);
    }
    for (int i = 0; i < r; i++) {
        int t0 = 0, t1 = 0;
        for (int j = 0; j < sz (v[0][i]); j++)
            t0 += v[0][i][j].se;
        for (int j = 0; j < sz (v[1][i]); j++)
            t1 += v[1][i][j].se;
        t1 = t0 = min (t0, t1); 
        for (int j = 0; j < sz (v[0][i]) && t0; j++)
            while (v[0][i][j].se && t0) {
                x[v[0][i][j].fi] /= p[i];
                t0--;
                v[0][i][j].se--;
            }
        for (int j = 0; j < sz (v[1][i]) && t1; j++)
            while (v[1][i][j].se && t1) {
                y[v[1][i][j].fi] /= p[i];
                t1--;
                v[1][i][j].se--;
            }
    }
    printf ("%d %d\n", n, m);
    for (int i = 0; i < n; i++) printf ("%d ", x[i]);
    printf ("\n");
    for (int i = 0; i < m; i++) printf ("%d ", y[i]);
    printf ("\n");
    return 0;
}