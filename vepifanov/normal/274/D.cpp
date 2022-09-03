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
int was[300000];
vi w[300000];
vi q;

int go (int x) {
    was[x] = 1;
    for (int i = 0; i < sz (w[x]); i++) {
        if (was[w[x][i]] == 1) re 1;
        if (!was[w[x][i]] && go (w[x][i])) re 1;
    }   
    was[x] = 2;
    if (x < m) q.pb (x);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    int ct = m;
    for (int i = 0; i < n; i++) {
        vii v;
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x);
            if (x != -1) v.pb (mp (x, j));
        }
        sort (all (v));
        int a = 0, b = 0, c = 0;
        while (b < sz (v) && v[b].fi == v[a].fi) b++;
        while (b < sz (v)) {
            c = b;
            while (c < sz (v) && v[c].fi == v[b].fi) c++;
            ct++;
            for (int t = a; t < b; t++) w[ct].pb (v[t].se);
            for (int t = b; t < c; t++) w[v[t].se].pb (ct);
            a = b;
            b = c;
        }
    }
    for (int i = 0; i < m; i++)
        if (!was[i])
            if (go (i)) {
                printf ("-1\n");
                re 0;
            }
    for (int i = 0; i < m; i++) printf ("%d ", q[i] + 1);
    printf ("\n");
    return 0;
}