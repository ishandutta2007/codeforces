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
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[100500];
ll dp[505][505];
long long ans;
void check(ll l, ll r) {
    ll p1 = a[l];
    ll p2 = b[r];
    ans += min(1, max(0, p1 - p2 + 1));
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        a[i] = k;
        b[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        a[x] = min(a[x], i);
        b[x] = max(b[x], i + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            check(i, i-1);
        }
        if (i < n) {
            check(i, i+1);
        }
        if (a[i] == k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}