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
ll y;
int was[16][1 << 16];
ll res[16][1 << 16];
int can[16];
int forb[16];
int ct;

ll go (int i, int mask) {
    if (i == n) re 1;
    if (was[i][mask] == ct) re res[i][mask];
    was[i][mask] = ct;
    ll cur = 0;
    for (int j = 0; j < n; j++)
        if (((mask >> j) & 1) == 0 && (can[j] == n || can[j] == i) && (mask & forb[j]) == 0)
            cur += go (i + 1, mask | (1 << j));
    re res[i][mask] = cur;
}

int main () {
    cin >> n >> y >> m; y -= 2000;
    for (int i = 0; i < m; i++) {
        int a, b;             
        scanf ("%d%d", &a, &b); a--; b--;
        forb[a] |= 1 << b;
    }
    for (int i = 0; i < n; i++) can[i] = n;
    ct++;
    if (go (0, 0) < y) {
        printf ("The times have changed\n");
        re 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            ct++;
            can[i] = j;
            ll cur = go (0, 0);
            if (cur >= y) break;
            y -= cur;
        }
    for (int i = 0; i < n; i++) printf ("%d ", can[i] + 1);
    return 0;
}