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
ll a[MAXN], b[MAXN], cnt[MAXN], oth[MAXN];
map<pii, ll> f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i] = a[i];
        ans += a[i];
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        auto it = f.find(mp(x, y));
        if (it != f.end()) {
            ll z = it->Y;
            f.erase(it);
            if (x == z) {
                cnt[x]++;
                if (cnt[x] > oth[x]) {
                    ans++;
                }
            } else {
                if (cnt[z] >= oth[z]) {
                    ans++;
                }
                oth[z]--;
            }
        }
        if (z == 0) {
            cout << ans << "\n";
            continue;
        }
        f[mp(x,y)] = z;
        if (x == z) {
            cnt[x]--;
            if (cnt[x] >= oth[x]) {
                ans--;
            }
        } else {
            oth[z]++;
            if (cnt[z] >= oth[z]) {
                ans--;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}