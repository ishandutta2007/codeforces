#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
pii a[300500];
vector<pair<pii, ll> > ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i].Y = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        a[x].X += z;
        a[y].X -= z;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        if (a[i].X < 0) {
            a[i].X = -a[i].X;
        }
    }
    ll l = 1, r = n;
    while (l < r) {
        ll x = min(a[l].X, a[r].X);
        if (x > 0) {
            ans.push_back(mp(mp(a[l].Y, a[r].Y), x));
        }
        a[l].X -= x;
        a[r].X -= x;
        if (a[l].X == 0) {
            l++;
        }
        if (a[r].X == 0) {
            r--;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.X.Y << " " << x.X.X << " " << x.Y << "\n";
    }
    return 0;
}