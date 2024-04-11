#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
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
pii a[100500];
multiset<ll> fr;
multiset<ll> used;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> y >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
    }
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll l = a[i].X;
        ll r = a[i].Y;
        while (!used.empty()) {
            auto val = *(used.begin());
            if (val < l) {
                used.erase(used.find(val));
                fr.insert(val);
            } else
                break;
        }
        if (fr.empty()) {
            used.insert(r);
            ans += y + x * (r-l);
            ans %= MOD;
        } else {
            auto itr = fr.end();
            itr--;
            auto val = *itr;
            if (x * (r - val) <= y + x * (r - l)) {
                fr.erase(fr.find(val));
                ans += x * (r - val);
                ans %= MOD;
            } else {
                ans += y + x * (r-l);
                ans %= MOD;
            }
            used.insert(r);
        }
    }
    cout << ans << endl;


    return 0;
}