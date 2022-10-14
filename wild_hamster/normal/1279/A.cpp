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
set<pii> f;
ll a[200500];

int main() {
    ll t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a, a+3);
        if (a[0] + a[1] + 1 < a[2]) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}