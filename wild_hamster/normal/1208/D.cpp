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
#define MOD 998244353
#define pii pair<ll,ll>

typedef long long ll;
using namespace std;
#define MAXN 400228
#define SQ 700
ll x, y, n, m, k, i, j, q;
ll a[MAXN], b[MAXN];
map<ll, ll> f;

ll t[2 * MAXN];
int N;

void build() {  // build the tree
    for (int i = N - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
    for (t[p += N] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    N = n+1;
    for (int i = 0; i <= n; i++) {
        t[i+N+1] = i + 1;
    }
    build();

    for (int i = n-1; i >= 0; i--) {
        ll l = 0, r = n;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll sum = query(0, mid + 1);
            if (sum > a[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        modify(l, 0);
        b[i] = l;
    }

    for (int i = 0; i < n; i++) {
        int x = b[i];
        printf("%d ", x);
    }
    cout << endl;

    return 0;
}