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
int cnt[5000];
ll all[5000];
ll res;
int ea[5000];
int eb[5000];
int ec[5000];
vii v[5000];

int go (int x, int p) {
    cnt[x] = 1;
    all[x] = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        go (y, x);
        cnt[x] += cnt[y];
        all[x] += all[y] + (ll)z * cnt[y];
    }
    re 0;
}

ll go2 (int x, int p, int s, ll up) {
    res = min (res, all[x] + up);
    ll ans = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        ans += (ll)z * cnt[y] * (s - cnt[y]);
        ans += go2 (y, x, s, up + all[x] - (ll)z * cnt[y] - all[y] + (ll)(s - cnt[y]) * z);
    }
    re ans;
}

pair<pair<ll, ll>, int> calc (int s, int t) {
    go (s, t);
    res = 1e18;
    ll sum = go2 (s, t, cnt[s], 0);
    re mp (mp (sum, res), cnt[s]);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        ea[i] = a;
        eb[i] = b;
        ec[i] = c;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    ll ans = 1e18;
    for (int i = 0; i + 1 < n; i++) {
        pair<pair<ll, ll>, int> a = calc (ea[i], eb[i]);
        pair<pair<ll, ll>, int> b = calc (eb[i], ea[i]);
        ll cur = a.fi.fi + b.fi.fi + a.fi.se * b.se + b.fi.se * a.se + (ll)ec[i] * a.se * b.se;
        ans = min (ans, cur);
    }
    cout << ans << endl;
    return 0;
}