#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
pii a[300500];
vector<pii> f;
string s;

ll t[1005000], t1[1005000];

void modify(int p, ll value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}


void modify1(int p, ll value) {  // set value at position p
    for (t1[p += n] = value; p > 1; p >>= 1) t1[p>>1] = t1[p] + t1[p^1];
}

ll query1(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t1[l++];
        if (r&1) res += t1[--r];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i;
    }
    sort(a, a+n);
    ll inv_num = 0;
    for (int i = 0; i < n; i++) {
        ll pos = a[i].Y;
        inv_num += query(pos, n);
        modify(pos, 1);
        modify1(pos, pos);
        ll l = 0, r = n-1;
        ll val = i / 2 + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (query(0, mid + 1) < val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        ll sumleft = query1(0, l+1);
        ll sumright = query1(l+1, n);
        ll oval = i + 1 - val;
        //cout << inv_num << "\n";
        cout << inv_num + (l * val - sumleft) + (sumright - l * oval) - val * (val - 1) / 2 - oval*(oval+1)/2 << " ";
    }
    return 0;
}