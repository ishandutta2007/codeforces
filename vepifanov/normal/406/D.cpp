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

const int N = 1e5;

int n;
int m;
int q[N];
ll x[N];
ll y[N];
int anc[N][20];
int tin[N];
int tout[N];
vi v[N];
int ct = 0;

ll vect (int a, int b, int c) {
    re (x[b] - x[a]) * (y[c] - y[b]) - (y[b] - y[a]) * (x[c] - x[b]);
}

int isanc (int a, int b) { re int (tin[a] <= tin[b] && tout[a] >= tout[b]); }

int go (int x, int p) {
    tin[x] = ct++;
    anc[x][0] = p;
    for (int t = 0; t < 19; t++)
        anc[x][t + 1] = anc[anc[x][t]][t];
    for (int i = 0; i < sz (v[x]); i++)
        go (v[x][i], x);
    tout[x] = ct++;
    re 0;
}

int lca (int a, int b) {
    int j = 19;
    while (!isanc (a, b))
        if (j == 0 || !isanc (anc[a][j], b))
            a = anc[a][j];
        else
            j--;    
    re a;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%I64d%I64d", &x[i], &y[i]);
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (r > 1 && vect (i, q[r - 1], q[r - 2]) > 0) r--;
        q[r++] = i;
        if (r >= 2) v[q[r - 2]].pb (i);
    }
    go (n - 1, n - 1);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        printf ("%d ", lca (a, b) + 1);
    }
    printf ("\n");
    return 0;
}