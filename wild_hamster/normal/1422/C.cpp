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
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, w, r;
ll c[1005000], b[1005000], a[1005][1005], dp[1005000], maxdp[1005000];
vector<ll> f, g;
ll t, x, y, z;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    n = s.size();
    ll p = 1;
    for (int i = 0; i <= n + 5; i++) {
        b[i+1] = (b[i] + p * (i + 1)) % MOD;
        c[i] = p;
        p = p * 10 % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (1LL * i * (i + 1) / 2) * (s[i] - '0') % MOD * c[n-i-1] % MOD;
        ans %= MOD;
        ans += b[n-i-1] * (s[i] - '0');
        ans %= MOD;
    }
    cout << ans << "\n";

    return 0;
}