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
int res[100000];
int was[100000][4];
int use[100000];
vii v[100000];

int put (int x, int y) {
    res[x] = y;
    for (int i = 0; i < sz (v[x]); i++)
        was[v[x][i].fi][y] = was[v[x][i].se][y] = 1;
    re 0;
}

int go (int x) {
    if (use[x]) re 0;
    use[x] = 1;
    int a = res[x];
    for (int i = 0; i < sz (v[x]); i++) {
        int p = v[x][i].fi, q = v[x][i].se;
        if (res[p] && res[q]) continue;
        if (res[p] && !res[q]) {
            put (q, 6 - a - res[p]);
            go (p);
            go (q);
        } else
        if (!res[p] && res[q]) {
            put (p, 6 - a - res[q]);
            go (p);
            go (q);
        } else
        for (int b = 1; b <= 3; b++)
            if (a != b && !was[p][b]) {
                int c = 6 - a - b;
                if (!was[q][c]) {
                    put (p, b);
                    put (q, c);
                    go (p);
                    go (q);
                    break;
                }
            }
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--; c--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
        v[c].pb (mp (a, b));
    }
    for (int i = 0; i < n; i++)
        if (!use[i]) {
            put (i, 1);
            go (i);
        }   
    for (int i = 0; i < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}