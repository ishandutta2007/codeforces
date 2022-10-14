#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;


ll b[200500];
ll a[200500], c[200500], pl[200500], pr[200500], val[200500], revb[200500], used[200500];
vector<ll> comp;
ll g[200500], g2[200500];

ll calc(ll tl, ll tr) {
    if (tl > tr) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
    }
    for (int i = tl; i <= tr; i++) {
        used[b[i]] = 1;
    }
    ll pos = 0;
    for (int i = n; i >= 1; i--) {
        if (used[i]) {
            revb[i] = pos++;
        }
    }
    for (int i = tl; i <= tr; i++) {
        g2[i-tl] = revb[b[i]];
    }

    for (int i = 0; i < tr-tl+1; i++) {
        g[g2[i]] = i;
    }
    ll m = tr-tl+1;
    for (int i = 0; i < tr-tl+1; i++) {
        pl[i] = i + 1;
        pr[i] = i - 1;
        val[i] = 0;
    }
    for (int i = 0; i < tr-tl+1; i++) {
        ll v = g[i];
        pl[v] = pr[v] = v;
        bool is_l = (v > 0 && pr[v-1] == v-1);
        bool is_r = (v < m - 1 && pl[v+1] == v + 1);
        ll l, r;
        l = r = v;
        if (is_l) {
            l = pl[v-1];
        }
        if (is_r) {
            r = pr[v+1];
        }
        
        val[l] = val[r] = max(val[l], val[r]) + 1;
        pl[l] = l;
        pr[r] = r;
        pr[l] = r;
        pl[r] = l;
    }

    return val[0];
}
ll gt(ll x) {
    ll p = 0;
    ll t = calc(0, x-1);
    ll tt = calc(x, n-2);
    return max(t, tt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            k = i;
        }
    }
    ll pos = 0;
    for (int i = k + 1; i < n; i++) {
        b[pos++] = a[i];
    }
    for (int i = 0; i < k; i++) {
        b[pos++] = a[i];
    }


    ll l = 0, r = pos;
    while (r - l > 2) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll fm1 = gt(m1);
        ll fm2 = gt(m2);
        if (fm1 <= fm2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    ll cur_ans = MOD, pi = -1;
    for (int i = l; i <= r; i++) {
        ll p = gt(i);
        if (p <= cur_ans) {
            cur_ans = p;
            pi = i;
        }
    }
    cout << cur_ans+1 << " " << (k + (n - (n - 1 - pi)) + 2 * n ) % n << endl;
    return 0;
}