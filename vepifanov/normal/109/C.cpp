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
int cnt[100000], sum[100000];
ll res[100000];
vii v[100000];

int get (int x) {
    while (x) {
        if (!(x % 10 == 4 || x % 10 == 7)) re 0;
        x /= 10;
    }
    re 1;
}

int go (int x, int p) {
    cnt[x] = 0;
    sum[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi, z = v[x][i].se;
        if (y == p) continue;
        go (y, x);
        if (z) cnt[x] += sum[y]; else cnt[x] += cnt[y];
        sum[x] += sum[y];
    }
    re 0;
}

int go2 (int x, int p, int up) {
    res[x] = up + cnt[x];
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi, z = v[x][i].se;
        if (y == p) continue;
        if (z) go2 (y, x, n - sum[y]); else go2 (y, x, up + cnt[x] - cnt[y]);
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        c = get (c);
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    go (0, -1);
    go2 (0, -1, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += res[i] * (res[i] - 1);
    cout << ans << endl;
    return 0;
}