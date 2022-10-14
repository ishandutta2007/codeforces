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
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3, l;
ll a[2005][2005];
ll ax[2005], ay[2005];
ll bx[2005], by[2005];
ll st[1000050];
vector<ll> g[1050000];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> n >> m;
    for (int i = 0; i <n ; i++) {
        cin >> ax[i] >> ay[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> bx[i] >> by[i];
    }
    ll ans = 2500000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x = max(0LL, bx[j] - ax[i] + 1);

            ll y = max(0LL, by[j] - ay[i] + 1);
            g[x].push_back(y);
            st[y]++;
        }
    }
    ll pos = 1000005;
    while (st[pos] == 0 && pos > 0) {
        pos--;
    }
    ans = pos;
    for (int i = 0; i <= 1000005; i++) {
        for (auto x : g[i]) {
            st[x]--;
        }
        while (st[pos] == 0 && pos > 0) {
            pos--;
        }
        ans = min(ans, pos + i);
    }
    cout << ans << "\n";

    return 0;
}