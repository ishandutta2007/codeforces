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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[2000500], b[205000], c[200500], fac[55];
vector<ll> g;
ll dp[55];
map<ll, ll> f;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k + 1; i++) {
        cout << "?";
        for (int j = 0; j < k + 1; j++) {
            if (i == j) {
                continue;
            }
            cout << " " << j + 1;
        }
        cout << endl;
        fflush(stdout);
        cin >> y >> x;
        f[x]++;
    }
    for (auto it = f.begin(); it != f.end(); it++) {
        g.push_back(it->X);
    }
    cout << "! " << f[g[1]] << "\n";
    return 0;
}