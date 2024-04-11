#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll,ll>

typedef long long ll;
using namespace std;
#define MAXN 1488228
#define N 1000000
ll x, y, n, m, k, i, j, q, w;
ll cur[MAXN * 2], pres[MAXN], a[MAXN], t[MAXN * 2];

vector<ll> f;

ll phis[1005000];
ll pr[1005000];

int main() {
    cin.tie(0);  ios_base::sync_with_stdio(0);
    for (int i = 2; i <= N; i++) {
        pr[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        phis[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            phis[j] -= phis[i];
        }
    }
    cin >> n >> k;
    ll ans = (ll)1e+18;
    for (int j = 0; j < 2; j++) {
        f.clear();
        for (int i = 3; i <= n; i++) {
            if (j == 0 || i % 2 == 1) {
                f.push_back(phis[i]);
            }
        }
        if (k > f.size()) {
            continue;
        }
        ll sum = 1 - j;
        sort(f.begin(), f.end());
        for (int i = 0; i < k; i++) {
            sum += f[i];
        }
        ans = min(ans, sum);
    }
    cout << ans + 1 << endl;
    return 0;
}