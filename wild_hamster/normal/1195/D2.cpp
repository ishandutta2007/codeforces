#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 3005
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[100500], b[100500], p[50];
ll get_len(ll x) {
    ll y = 0;
    while (x) {
        x /= 10;
        y++;
    }
    return y;
}
ll add(ll& x, ll y) {
    x += y;
    x %= MOD;
}
vector<ll> f;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    p[0] = 1;
    for (int i = 1; i < 50; i++) {
        p[i] = p[i-1] * 10 % MOD;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[get_len(a[i])]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        f.clear();

        ll x = a[i];
        while (x) {
            f.push_back(x % 10);
            x /= 10;
        }
        for (int k = 0; k < f.size(); k++) {
            for (int j = 1; j <= 10; j++) {
                add(ans, b[j] * p[k + min(k, j)] * f[k]);
                add(ans, b[j] * p[k + min(k + 1, j)] * f[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}