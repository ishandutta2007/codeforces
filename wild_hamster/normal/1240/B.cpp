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

typedef int ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll a[300500], b[300500], c[300500];
vector<pii> f;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            b[i] = c[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (b[a[i]] == -1) {
                b[a[i]] = c[a[i]] = i;
            } else {
                b[a[i]] = min(b[a[i]], i);
                c[a[i]] = max(c[a[i]], i);
            }
        }
        f.clear();
        for (int i = 1; i <= n; i++) {
            if (b[i] == -1) {
                continue;
            }
            f.push_back(mp(b[i], c[i]));
        }
        ll sz = f.size();
        ll ans = 1;
        ll p = 1;
        for (int i = 1; i < sz; i++) {
            if (f[i].X > f[i-1].Y) {
                p++;
            } else {
                ans = max(ans, p);
                p = 1;
            }
        }
        ans = max(ans, p);
        cout << sz - ans << "\n";
    }
    return 0;
}