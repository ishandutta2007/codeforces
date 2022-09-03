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
int m, k;
int d[300000];
int q[300000];
int f[100000];
vi v[300000];
int p[300000];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf ("%d", &x); x--;
        f[x] = 1;
    }
    for (int i = 0; i < n; i++) v[i].reserve (100);
    for (int i = n; i < n + m; i++) v[i].reserve (2);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (n + i);
        v[n + i].pb (a);
        v[n + i].pb (b);
        v[b].pb (n + i);
    }
    int S, T;
    scanf ("%d%d", &S, &T); S--; T--;
    f[T] = f[S] = 1;
    for (int i = 0; i < n + m; i++)
        d[i] = 1e9;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
        if (f[i]) {
            d[i] = 0;
            q[r++] = i;
        }   
    for (int i = 0; i < n + m; i++) p[i] = i;
    for (int e = 1; e <= n; e++) {
        while (l < r) {
            int x = q[l];
            if (d[x] == e) break;
            l++;
            for (int i = 0; i < sz (v[x]); i++) {
                int y = v[x][i];
                int z = d[x] + 1;
                if (d[y] > z) {
                    d[y] = z;
                    q[r++] = y;
                }
                if (d[y] == z) {
                    int a = gp (x);
                    int b = gp (y);
                    if (a != b) {
                        if (rand () & 1)
                            p[a] = b;
                        else
                            p[b] = a;
                    }
                }
            }
        }
        if (gp (S) == gp (T)) {
            printf ("%d\n", e);
            re 0;
        }
    }   
    printf ("-1\n");
    return 0;
}