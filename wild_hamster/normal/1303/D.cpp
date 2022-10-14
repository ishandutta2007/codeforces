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
ll w[27][27];
vector<ll> g[27];
ll used[27];
vector<ll> comp;
void dfs(ll v, ll p = - 1) {
    comp.push_back(v);
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < 30; i++) {
            a[i] = 0;
        }
        ll tot_sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> x;
            tot_sum += x;
            y = 0;
            while (x) {
                x /= 2;
                y++;
            }
            y--;
            a[y]++;
        }
        if (tot_sum < n) {
            cout << -1 << "\n";
            continue;
        }

        ll sum = 0;
        ll ans = 0;
        for (int i = 0; i < 60; i++) {
            sum += a[i] * (1LL << i);
            if ((n >> i) & 1) {
                if (sum >= (1LL << i)) {
                    sum -= (1LL << i);
                } else {
                    for (int j = i + 1; j < 60; j++) {
                        if (a[j] >= 1) {
                            a[j]--;
                            ans += j - i;
                            for (int k = i; k < j; k++) {
                                a[k]++;
                            }
                            a[i]++;
                            break;
                        }
                    }
                    sum += 2 * (1LL << i);
                    sum -= (1LL << i);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}