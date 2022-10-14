#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
typedef int ll;
using namespace std;
ll n, m, k, x, y, z;

const int N = 1e6 + 5;  // limit for array size
int t[2 * N];
ll a[2005000];

ll Abs(ll x) {
    return x > 0 ? x : -x;
}

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = MOD;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(res, t[--r]);
    }
    return res;
}


int main() {
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        t[n+i+1] = t[n+i];
        if (s[i] == '(') {
            t[n+i+1]++;
        } else {
            t[n+i+1]--;
        }
    }
    build();
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        l--;r--;
        ll lval = query(l, l+1);
        ll rval = query(r+1, r+2);
        ll diff = rval - lval;
        ll mn = query(l, r + 2) - lval;
        cout << (r - l + 1) - (Abs(mn) + diff - mn) << "\n";
    }
    return 0;
}