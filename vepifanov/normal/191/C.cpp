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
int ct = 0;
vii v[100000];
int anc[100000][20];
int tin[100000];
int tout[100000];
int res[100000];
int u[100000];
int w[100000];

int go (int x, int p) {
    tin[x] = ct++;
    anc[x][0] = p;
    for (int i = 0; i < 19; i++)
        anc[x][i + 1] = anc[anc[x][i]][i];
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i].fi != p)
            go (v[x][i].fi, x);
    tout[x] = ct++;
    re 0;
}

int isanc (int a, int b) {
    re tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    int j = 19;
    while (!isanc (a, b))
        if (j > 0 && isanc (anc[a][j], b))
            j--;
        else
            a = anc[a][j];  
    re a;
}

int go2 (int x, int p, int e) {
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i].fi != p) {
            go2 (v[x][i].fi, x, v[x][i].se);
            u[x] += u[v[x][i].fi];
            w[x] += w[v[x][i].fi];
        }   
    if (e != -1) res[e] = u[x] - 2 * w[x];
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (mp (b, i));
        v[b].pb (mp (a, i));
    }
    go (0, 0);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        u[a]++;
        u[b]++;
        int c = lca (a, b);
        w[c]++;
    }
    go2 (0, 0, -1);
    for (int i = 0; i + 1 < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}