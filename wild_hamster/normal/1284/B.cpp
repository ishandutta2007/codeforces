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
#define OFF 200001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll a[300500], b[300500];
vector<ll> f, g;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ll nn = n;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ll mn = MOD, mx = -MOD;
        ll bad = 0;
        for (int j = 0; j < x; j++) {
            ll y;
            cin >> y;
            mn = min(mn, y);
            if (y > mn) {
                bad = 1;
            }
            mx = max(mx, y);
        }

        if (!bad) {
            f.push_back(mx);
            g.push_back(mn);
        } else {
            ans += 2 * nn - 1;
            nn--;
        }
    }
    sort(f.begin(), f.end());
    for (int i = 0; i < nn; i++) {
        ll x = upper_bound(f.begin(), f.end(), g[i]) - f.begin();
        ans += nn - x;
    }
    cout << ans << "\n";
    return 0;

}