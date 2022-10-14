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

ll a[200500], b[200500], p[50];
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
set<pii> f;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        f.clear();
        ll n = s.size();
        for (int i = 0; i < n; i++) {
            a[i+1] = a[i] + s[i] - '0';
        }
        for (int i = 0; i < n; i++) {
            ll x = 0;
            for (int j = i; j < min(i + 22LL, n); j++) {
                x = x * 2 + s[j] - '0';
                ll l = j - i + 1;
                ll diff = x - l;
                if (diff >= 0 && diff <= i) {
                    ll sum = a[i] - a[i-diff];
                    if (sum == 0) {
                        f.insert(mp(i-diff, j));
                    }
                }
            }
        }
        cout << f.size() << "\n";
    }
    return 0;
}