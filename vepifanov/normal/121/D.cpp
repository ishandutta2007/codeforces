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

const ll MAX = 1e17;

int n, u = 0;
ll m;

ll l[100001], r[100001];
ll cl[1000001], cr[1000001];
ll sl[1000001], sr[1000001];
ll md;

ll v[1000000];

int go (ll x) {
    if (x > 0) v[u++] = x;
    if (x <= MAX) {
        go (x * 10 + 4);
        go (x * 10 + 7);
    }
    re 0;
}

ll calc (ll a, ll b) {
    if (a == 0 || b == 0) re 0;
    if (a > m / b) re m + 1;
    re a * b;
}

int main () {
    cin >> n >> m;
    md = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        md = min (md, r[i] - l[i]);
    }   
    go (0);
    sort (v, v + u);
    sort (l, l + n);
    sort (r, r + n);
    reverse (r, r + n);
    sl[n - 1] = sr[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        sl[i] = min (sl[i + 1] + calc (n - i - 1, l[i + 1] - l[i]), m + 1);
        sr[i] = min (sr[i + 1] + calc (n - i - 1, r[i] - r[i + 1]), m + 1);
    }
    int x = n;
    for (int i = u - 1; i >= 0; i--) {
        while (x > 0 && l[x - 1] >= v[i]) x--;
        if (x < n) cl[i] = min (sl[x] + calc (n - x, l[x] - v[i]), m + 1);
    }
    x = n;
    for (int i = 0; i < u; i++) {
        while (x > 0 && r[x - 1] <= v[i]) x--;
        if (x < n) cr[i] = min (sr[x] + calc (n - x, v[i] - r[x]), m + 1);
    }
    x = u - 1;
    int y = u - 1;
    int ans = 0;
    while (x >= 0) {
        while (y >= x && (v[y] - v[x] > md || cl[x] + cr[y] > m)) y--;
        if (x <= y) ans = max (ans, y - x + 1);
        x--;
    }
    printf ("%d\n", ans);
    return 0;
}