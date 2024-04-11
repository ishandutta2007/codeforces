#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>

#define X first
#define Y second
#define mp make_pair
#define MOD 998244353
#define pii pair<ll,ll>

typedef int ll;
using namespace std;
#define MAXN 400228
#define SQ 700
ll x, y, n, m, k, i, j, q;
ll a[MAXN], b[MAXN];
map<ll, ll> f;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll z;
        cin >> x >> y >> z;
        if (z % 3 == 0) {
            cout << x << endl;
        } else if (z % 3 == 1) {
            cout << y << endl;
        } else {
            cout << (x^y) << endl;
        }
    }
    return 0;
}