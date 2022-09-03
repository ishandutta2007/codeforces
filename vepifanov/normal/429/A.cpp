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
int y[100000];
int z[100000];
vi res;

int go (int x, int p, int a, int b) {
    int now = y[x] ^ z[x] ^ a;
    if (now) res.pb (x + 1);
    for (int i = 0; i < sz (v[x]); i++) {
        if (v[x][i] == p) continue;
        go (v[x][i], x, b, a ^ now);
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &z[i]);
    go (0, 0, 0, 0);
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d\n", res[i]);
    return 0;
}