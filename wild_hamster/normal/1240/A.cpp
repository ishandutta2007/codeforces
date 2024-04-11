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
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
ll a[300500], b[300500], c[300500];
vector<pii> f;
ll find_ans(ll m) {
    for (int i = 0; i < m; i++) {
        b[i] = 0;
    }
    for (int i = x1-1; i < m; i += x1) {
        b[i] += p1;
    }

    for (int i = x2-1; i < m; i += x2) {
        b[i] += p2;
    }
    sort(b, b+m);
    reverse(b, b+m);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += b[i] * a[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] /= 100;
        }
        cin >> p1 >> x1;
        cin >> p2 >> x2;
        cin >> k;
        sort(a, a+n);
        reverse(a, a+n);
        if (find_ans(n) < k) {
            cout << "-1\n";
            continue;
        }
        ll l = 1, r = n;
        while (l < r) {
            ll mid = (l + r)/ 2;
            if (find_ans(mid) < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << l << "\n";
    }
    return 0;
}