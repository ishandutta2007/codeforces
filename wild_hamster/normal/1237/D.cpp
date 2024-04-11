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

ll b[600500], p[600500];
struct hyu {
    ll x;
    ll y;
    ll z;
    ll num;
};

ll a[500500];
ll mn[300500][20], mx[300500][20], pr[3005000];

ll find_min(ll l, ll r) {
    if (l > r) {
        return MOD;
    }
    ll p = pr[r-l+1];
    return min(mn[l][p], mn[r-(1<<p)+1][p]);
}


ll find_max(ll l, ll r) {
    ll p = pr[r-l+1];
    return max(mx[l][p], mx[r-(1<<p)+1][p]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 20; i++) {
        pr[(1<<i)] = i;
    }
    for (int i = 1; i < 1000000; i++) {
        pr[i] = max(pr[i], pr[i-1]);
    }
    cin >> n;
    ll min1 = MOD, max1 = -MOD;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        min1 = min(min1, a[i]);
        max1 = max(max1, a[i]);
    }
    if (min1 * 2 >= max1) {
        for (int i = 0; i < n; i++) {
            cout << -1 << " ";
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        a[i+n] = a[i+2*n] = a[i];
    }
    n *= 3;
    for (int i = 0; i < n; i++) {
        mn[i][0] = a[i];
        mx[i][0] = a[i];
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i+(1<<j) <= n; i++) {
            mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
            mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
        }
    }

    for (int i = 0; i < n / 3; i++) {
        ll pos = i;
        while (true) {
            ll l = pos, r = n - 1;
            while (l < r) {
                ll mid = (l + r) / 2;
                ll min1 = find_min(pos + 1, mid);
                ll max1 = find_max(i, mid);
                //cout << min1 << " " << max1 << endl;
                if (min1 * 2 < max1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (pos + 1 == l) {
                cout << l - i << " ";
                break;
            }
            pos = l - 1;
        }
    }

    return 0;
}