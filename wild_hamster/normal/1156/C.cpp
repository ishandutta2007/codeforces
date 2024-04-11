#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[200500], b[100500];
ll dp[505][505];
bool fuck(string s) {
    for (int i = 0; i + 1 < s.size(); i++) {
        ll x = s[i] - s[i+1];
        if (x == 1 || x == -1) {
            return true;
        }
    }
    return false;
}
multiset<ll> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    ll l = 0, r = n / 2;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        ll cool = true;
        for (int i = 0, j = n - mid; i < mid; i++, j++) {
            if (a[i] + m > a[j]) {
                cool = false;
            }
        }
        if (!cool) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}