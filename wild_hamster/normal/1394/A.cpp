
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

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[1000500], b[1005000], dp[1000500], used[1005000];
vector<ll> f, g;
void solve() {
    cin >> n >> m >> k;
    m++;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > k) {
            f.push_back(x);
        } else {
            g.push_back(x);
        }
        sum += x;
    }
    if (f.empty()) {
        cout << sum << "\n";
        return;
    }
    sort(f.rbegin(), f.rend());
    sort(g.rbegin(), g.rend());
    ll pos1 = 1, pos2 = 0;
    x = n - 1;
    for (int i = 1; i < f.size(); i++) {
        a[i] = a[i-1] + f[i];
    }
    for (int i = 0; i < g.size(); i++) {
        b[i+1] = b[i] + g[i];
    }
    sum = f[0];
    ll ans = 0;
    for (int j = 0; j + 1 <= f.size() && m * j <= x; j++) {
        ll y = min((ll)g.size(), x - m * j);
        ll hyu = a[j] + b[y];
        //cout << j << " " << hyu << " " << sum << "\n";
        ans = max(ans, hyu + sum);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t = 1;
    while (t--) {
        solve();

    }
    return 0;
}