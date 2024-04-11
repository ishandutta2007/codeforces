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

ll go(ll l, ll r, ll m) {
    if (m == -1 || r == l) {
        return 0;
    }
    ll idx = -1;
    for (int i = l; i < r; i++) {
        if ((a[i] & (1<<m)) != ((a[i+1]) & (1<<m))) {
            idx = i + 1;
            break;
        }
    }
    if (idx == -1) {
        return go(l, r, m-1);
    } else {
        ll d = go(l, idx-1, m-1);
        ll e = go(idx, r, m-1);
        return (1<<m) + min(d,e);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    cout << go(0, n-1, 29) << endl;






    return 0;
}