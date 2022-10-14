#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
ll a[100500];
ll Abs(ll x) {
    return x>0?x:-x;
}
vector<pii> f;
int main() {
    string s;
    cin >> n;
    cin >> s;
    ll cnt = 0, cnt1 = 0;
    ll ans = 0;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            cnt++;
            t++;
        } else {
            if (cnt > 0) {
                f.push_back(mp(i - cnt, i - 1));
                ans = max(ans, cnt+1);
            }
            cnt = 0;
        }
    }
    if (cnt > 0) {
        f.push_back(mp(n - cnt, n - 1));
        ans = max(ans, cnt+ 1);
    }
    for (int i = 0; i + 1 < f.size(); i++) {
        if (f[i].Y + 2 == f[i+1].X)
            ans = max(ans, f[i+1].Y - f[i].X + 1);
    }
    ans = min(ans, t);
    cout << ans << endl;
    return 0;
}