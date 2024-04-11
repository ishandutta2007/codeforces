#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll,ll>

typedef long long ll;
using namespace std;
#define MAXN 1488228
#define SQ 700
ll x, y, n, m, k, i, j, q, w, N;
ll res[MAXN], pres[MAXN], a[MAXN], t[MAXN * 2];

set<ll> f;

void build() {  // build the tree
    for (int i = N - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}


ll query(int l, int r) {  // sum on interval [l, r)
    ll res = -MOD;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

void prepare(ll m) {
    N = m;
    for (int i = 0; i < N; i++) {
        t[i] = -MOD;
    }

    for (int i = N; i < 2*N; i++) {
        t[i] = a[i-N];
    }

    build();
}

void do_shit(ll n, ll m) {
    ll mx = 0;
    ll k = 0;
    for (int i = 0; i < m; i++) {
        if (mx < a[i]) {
            mx = a[i];
            k = i;
        }
    }
    prepare(m);
    if (mx == 0) {
        if (2 * m <= n) {
            return;
        }
        for (int i = n-m; i < m; i++) {
            res[i] += query(i - n + m, i + 1);
        }
    } else {
        pres[k] += mx;
        pres[n-(m-k)+1] -= mx;
        for (int i = 0; i < k; i++) {
            ll r = i;
            ll l = i - n + m;
            ll val = query(max(l, 0LL), min(r, m-1) + 1);
            if (val < 0) {
                if (l < 0 || r >= m) {
                    res[i] += 0;
                } else {
                    res[i] += val;
                }
            } else {
                res[i] += val;
            }
        }

        for (int i = n-(m-k)+1; i < n; i++) {
            ll r = i;
            ll l = i - n + m;
            ll val = query(max(l, 0LL), min(r, m-1) + 1);
            if (val < 0) {
                if (l < 0 || r >= m) {
                    res[i] += 0;
                } else {
                    res[i] += val;
                }
            } else {
                res[i] += val;
            }
        }
    }
}



int main() {
    cin.tie(0);  ios_base::sync_with_stdio(0);
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> a[j];
        }
        do_shit(w, m);
    }

    ll sum = 0;
    for (int i = 0; i < w; i++) {
        sum += pres[i];
        cout <<  sum + res[i] << " ";
    }

    return 0;
}