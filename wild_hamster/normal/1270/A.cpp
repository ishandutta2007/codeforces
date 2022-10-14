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
vector<ll> g[1005000];
ll dp[55];
vector<ll> f;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        ll mx = 0, my = 0;
        for (int i = 0; i < x; i++) {
            ll z;
            cin >> z;
            mx = max(mx, z);
        }


        for (int i = 0; i < y; i++) {
            ll z;
            cin >> z;
            my = max(my, z);
        }
        if (my > mx) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}