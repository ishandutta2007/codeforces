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
ll n,m,k, y, z, l, i, j, x, r;
map<ll, ll> f;


pii a[500500];
bool cmp(pii x, pii y) {
    return x.X + y.Y > x.Y + y.X;
}
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
    }
    sort(a, a+n, cmp);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i].X * i + a[i].Y * (n - i - 1);
    }
    cout << ans << endl;
    return 0;
}