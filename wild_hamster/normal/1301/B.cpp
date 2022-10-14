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
ll a[100500];
vector<ll> f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        a[0] = a[n+1] = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        f.clear();
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                if (a[i-1] >= 0) {
                    f.push_back(a[i-1]);
                }

                if (a[i+1] >= 0) {
                    f.push_back(a[i+1]);
                }
            }
        }
        sort(f.begin(), f.end());
        ll g = 0;
        if (f.size() != 0) {
            g = (f[0] + f.back()) / 2;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                a[i] = g;
            }
            if (i > 1) {
                ans = max(ans, abs(a[i] - a[i-1]));
            }
        }
        cout << ans << " " << g << "\n";
    }

    return 0;
}