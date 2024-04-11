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
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[200500], b[200500];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll s = 0;
        ll p = 0;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
        s += a[i];
        if (i != 3) {
            p = max(p, a[i]);
        }
    }
    if (s % 3 == 0 && s / 3 >= p) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


    return 0;
}