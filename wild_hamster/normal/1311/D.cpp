#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[200505], b[200505];
vector<ll> g[20050];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 1; i <= 20000; i++) {
        for (int j = i; j <= 20000; j += i) {
            g[j].push_back(i);
        }
    }
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        ll ans = MOD;
        vector<ll> hyu;
        for (int i = 1; i <= 20000; i++) {
            ll sum = abs(m - i);
            ll mn = MOD;
            ll pshex = 0;
            for (auto x : g[i]) {
                if (abs(x - n) < mn) {
                    mn = min(mn, abs(x - n));
                    pshex = x;
                }
            }
            sum += mn;
            ll pshez = 0;
            ll x = k / i * i;
            if (abs(x - k) < abs(x + i - k)) {
                pshez = x;
            } else {
                pshez = x + i;
            }
            sum += min(abs(x - k), abs(x + i - k));
            if (sum < ans) {
                ans = min(ans, sum);
                hyu = {pshex, i, pshez};
            }
        }
        cout << ans << "\n";
        cout << hyu[0] << " " << hyu[1] << " " << hyu[2] << "\n";
    }

    return 0;
}