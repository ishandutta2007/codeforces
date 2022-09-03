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
#define prev PREV
                         
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
int was[110];
vii w[110];
int x[110];
vi v;
int ea[110];
int eb[110];
int prev[110];
int preve[110];
int q[110];
int cf[1000];
int ct;
int o;

int addedge (int a, int b, int c) {
    w[a].pb (mp (b, o));
    cf[o] = c;
    o++;
    w[b].pb (mp (a, o));    
    cf[o] = 0;
    o++;
    re 0;
}

int go (int S, int T) {
    ct++;
    int l = 0, r = 0;
    q[r++] = S;
    while (l < r) {
        int x = q[l++];
        for (int j = 0; j < sz (w[x]); j++) {
            int y = w[x][j].fi;
            int z = w[x][j].se;
            if (cf[z] > 0 && was[y] != ct) {
                was[y] = ct;
                prev[y] = x;
                preve[y] = z;
                q[r++] = y;
            }
        }
        if (was[T] == ct) re 1;
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        int y = x[i];
        for (int j = 2; j * j <= y; j++)
            if (y % j == 0) {
                v.pb (j);
                while (y % j == 0) y /= j;
            }
        if (y > 1) v.pb (y);
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &ea[i], &eb[i]);
        ea[i]--;
        eb[i]--;
        if (ea[i] & 1) swap (ea[i], eb[i]);
    }
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    int ans = 0;
    for (int i = 0; i < sz (v); i++) {
        o = 0;
        for (int j = 0; j < n + 2; j++) w[j].clear ();
        int p = v[i];
        for (int j = 0; j < n; j++) {
            int y = x[j];
            int z = 0;
            while (y % p == 0) {
                y /= p;
                z++;
            }
            if (z > 0) {
                if (j & 1)
                    addedge (j, n + 1, z);
                else
                    addedge (n, j, z);  
            }
        }
        for (int j = 0; j < m; j++)
            addedge (ea[j], eb[j], 1e9);
        while (go (n, n + 1)) {
            ans++;
            int j = n + 1;
            while (j != n) {
                int k = prev[j];
                int e = preve[j];
                cf[e]--;
                cf[e ^ 1]++;
                j = k;
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}