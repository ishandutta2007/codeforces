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
int was[100000];
int was2[100000];
int use[100000];
vi v[100000];
vi rv[100000];
vi u[100000];
vi q, w;

int go (int x) {
    if (was[x]) re 0;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++)
        go (v[x][i]);
    q.pb (x);
    re 0;
}

int go2 (int x) {
    if (use[x]) re 0;
    w.pb (x);
    use[x] = 1;
    for (int i = 0; i < sz (u[x]); i++)
        go2 (u[x][i]);
    re 0;
}

int go3 (int x) {
    if (was2[x]) re 0;
    int cur = 1;
    was2[x] = 1;
    for (int i = 0; i < sz (rv[x]); i++)
        cur += go3 (rv[x][i]);
    re cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        rv[b].pb (a);
        u[a].pb (b);
        u[b].pb (a);
    }
    int ans = n;
    for (int i = 0; i < n; i++)
        if (!use[i]) {
            w.clear ();
            go2 (i);
            q.clear ();
            for (int j = 0; j < sz (w); j++)
                if (!was[w[j]])
                    go (w[j]);
            reverse (all (q));
            int ok = 1;
            for (int j = 0; j < sz (q); j++)
                if (go3 (q[j]) > 1) {
                    ok = 0;
                    break;
                }
            ans -= ok;
        }
    printf ("%d\n", ans);   
    return 0;
}