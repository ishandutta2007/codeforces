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
int was[100000][3];
ll res[100000][3];
int x[100000];

ll go (int i, int j) {
    if (i == n || j == 0) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    ll cur = 0;
    if (j == 1) {
        cur = max (go (i + 1, 0) + x[i], go (i + 1, 1) + x[i] - (1 - x[i] % 2));
        if (x[i] >= 2) cur = max (cur, go (i + 1, 3) + x[i] - x[i] % 2);
    } else
    if (j == 2) {
        cur = max (go (i + 1, 0) + x[i], go (i + 1, 1) + x[i] - (1 - x[i] % 2));
        if (x[i] >= 2) cur = max (cur, go (i + 1, 2) + x[i] - x[i] % 2);
    } else {
        cur = go (i + 1, 0) + x[i] - x[i] % 2;
        if (x[i] >= 2) cur = max (cur, go (i + 1, 3) + x[i] - x[i] % 2);
    }
    re res[i][j] = cur;
}

int main () {
    scanf ("%d", &n); n--;
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max (ans, go (i + 1, 1) + x[i]);
        if (x[i] >= 2) ans = max (ans, go (i + 1, 2) + x[i] - x[i] % 2);
    }
    printf ("%I64d\n", ans);
    return 0;
}