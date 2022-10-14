
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
ll n, m, k, x, y, w, r;
ll c[1005000], b[1005000], a[1005000], dp[1005000], maxdp[1005000];
vector<ll> f, g;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
bool good(ll i, ll j) {
    return ((a[i] - a[j]) >= Abs(b[i] - b[j]) + Abs(c[i] - c[j]));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //srand(time(0));
    cin >> r >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    b[0] = c[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = -(ll)1e+18;
    }
    for (int i = 1; i <= n; i++) {
        ll last_pos = max(0, i - 1000);
        ll val = -(ll)1e+18;
        for (int j = last_pos; j <= i-1; j++) {
            ll gd = good(i, j);
            if (gd) {
                val = max(val, dp[j] + 1);
            }
        }
        if (last_pos != 0) {
            val = max(val, maxdp[last_pos - 1] + 1);
        }

        dp[i] = val;
        //cout << dp[i] << "\n";
        maxdp[i] = max(maxdp[i - 1], val);
    }
    cout << maxdp[n] << "\n";


    return 0;
}