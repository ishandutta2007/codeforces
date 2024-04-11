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
#define MAXN 305000
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[100500], b[100500];

ll gcd(ll a, ll b) {
    return b == 0? a : gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    n /= g; m /= g;
    while (q--) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        ll p1 = 0, p2 = 0;
        if (x1 == 0) {
            p1 = y1 / n;
        } else {
            p1 = y1 / m;
        }

        if (x2 == 0) {
            p2 = y2 / n;
        } else {
            p2 = y2 / m;
        }
        if (p1 == p2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}