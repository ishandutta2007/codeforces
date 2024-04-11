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
ll c[1005000], b[1005000], a[1005005], dp[1005000], maxdp[1005000];
vector<ll> f, g;
ll t, x, y, z;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
vector<char> zal;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        ll k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '<') {
                k |= 1;
            }
            if (s[i] == '>') {
                k |= 2;
            }
        }
        if (k != 3) {
            cout << n << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            b[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                b[i] = 1;
                b[(i+1) % n] = 1;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += b[i];
        }
        cout << ans << "\n";
    }

    return 0;
}