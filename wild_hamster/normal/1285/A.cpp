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
ll a[200500], b[200500];

ll p[100500], pp[100500];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a,b);
}
vector<ll> f;

ll shit(ll n) {
    f.clear();
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            f.push_back(i);
            f.push_back(n/i);
        }
    }
    ll l = (ll)1e+13;
    ll rx, ry;
    for (auto x : f) {
        for (auto y : f) {
            if (x * y >= n && lcm(x, y) == n) {
                if (max(x,y) < l) {
                    l = max(x, y);
                    rx = x;
                    ry = y;
                }
            }
            if (x == y) {
                break;
            }
        }
    }
    return max(rx, ry);
}

ll shit2(ll n) {
    ll p = (ll)1e+13;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0 && gcd(i, n/i) == 1) {
            p = min(p, max(i, n/i));
        }
    }
    return p;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    /*ll x = 0;
    for (ll i = 0; i <= 100000; i += 3) {
        for (ll j = 0; j < 100000; j+= 3) {
            if (i * j > 34000LL * 100000) {
                x++;
            }
        }
    }
    cout << x << endl;
    cout << 50000 << "\n";
    for (ll i = 2; i <= 99999; i += 2) {
        cout << i << " ";
    }
    cout << 100000 << "\n";*/

    ll n;
    cin >> n;
    cout << n+1 << endl;




    return 0;
}