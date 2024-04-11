
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
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef int ll;
using namespace std;
#define N 10000000
#define OFF 400001
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll ii;
ll a[200500], b[200500], c[200500], dp[2005000];
vector<ll> f;

void apply(string& hyu, ll n) {
    for (int i = 0; i < n; i++) {
        hyu[i] = (hyu[i] == '1' ? '0' : '1');
    }
    reverse(hyu.begin(), hyu.begin()+n);
}
void solve() {
    cin >> n;
    ll p = 2 * n;
    f.clear();
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }
    while (p > 0) {
        ll mx=  0;
        for (int i = 0; i < p; i++) {
            mx = max(mx, a[i]);
        }
        ll s = 0;
        for (int i = 0; i < p; i++) {
            if (a[i] == mx) {
                s = i;
            }
        }
        f.push_back(p - s);
        p = s;
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (auto x : f) {
        if (x > n) {
            continue;
        }
        for (int i = n; i >= 0; i--) {
            if (i >= x) {
                dp[i] = max(dp[i], dp[i - x]);
            }
        }
    }
    if (dp[n] == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}