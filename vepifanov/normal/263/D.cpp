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
vi v[100000];
int prev[100000];
int was[100000];
int d[100000];
int k;

int go (int x, int l) {
    d[x] = l;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (was[y] == 1) {
            if (d[x] - d[y] >= k) {
                printf ("%d\n", d[x] - d[y] + 1);
                while (x != y) {
                    printf ("%d ", x + 1);
                    x = prev[x];
                }
                printf ("%d\n", y + 1);
                re 1;
            }
        } else
        if (!was[y]) {
            prev[y] = x;
            if (go (y, l + 1)) re 1;
        }
    }
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    go (0, 0);
    return 0;
}