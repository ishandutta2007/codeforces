#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef int ll;
using namespace std;
ll n, m,k, y, z, l, i, j, x, r, fsz;
ll b[1000050], p[1000500], dp[500500], BB, pp, used[500500];
vector<pii> ans, f;

const int N = 10000000;
int lp[N+1], lpp[N+1];
vector<int> pr;

vector<ll> g;
vector<ll> divs[N + 2];

void go(ll d, ll x) {
    if (x == pp) {
        g.push_back(d);
        return;
    }
    ll r = 1;
    for (int i = 0; i <= f[x].Y; i++) {
        go(d * r, x + 1);
        r *= f[x].X;
    }
}

void generate_divisors(ll x) {
    f.clear();
    g.clear();
    ll lst = 1;
    while (x != 1) {
        if (lp[x] != lst) {
            lst = lp[x];
            f.push_back(mp(lp[x], 1));
        } else {
            f.back().Y++;
        }
        x = lpp[x];
    }
    pp = f.size();
    go(1, 0);
}

void try_shit(ll x, ll y) {
    if (divs[x].size() < 2)
        divs[x].push_back(y);
}
int main() {

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 2; i <= N; i++) {
        lpp[i] = i / lp[i];
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        p[i] = b[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        ll y = b[i];
        generate_divisors(y);
        for (auto x : g) {
            try_shit(x, y);
        }
    }
    long long mx = (long long)1e+18, mr1, mr2;
    for (int i = 1; i <= N; i++) {
        ll mx1 = 1e+9, mx2 = 1e+9;
        if (divs[i].size() < 2) {
            continue;
        }
        mx1 = divs[i][0], mx2 = divs[i][1];

        if (mx2 != 1e+9 && 1LL * mx1 * mx2 / i < mx) {
            mx = 1LL * mx1 * mx2 / i;
            mr1 = mx1;
            mr2 = mx2;
        }
    }
    ll ans1 = -1, ans2 = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] == mr1 && ans1 == -1) {
            ans1 = i + 1;
        } else if (p[i] == mr2 && ans2 == -1) {
            ans2 = i+1;
        }
    }

    cout << min(ans2, ans1) << " " << max(ans2, ans1) << endl;
    return 0;

}