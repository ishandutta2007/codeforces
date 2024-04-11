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
#define MAXN 300500
#define OFF 200001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll a[205000], b[200500];
vector<pii> f[4];

bool cmp(pii x, pii y) {
    return x.X * y.Y < x.Y * y.X;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            f[j].clear();
        }
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            ll x = a[j] - a[i];
            ll y = b[j] - b[i];
            if (x <= 0 && y < 0) {
                f[2].push_back(mp(-x, -y));
            }
            if (x > 0 && y >= 0) {
                f[0].push_back(mp(x, y));
            }
            if (x <= 0 && y >= 0) {
                f[1].push_back(mp(-x, y));
            }
            if (x > 0 && y < 0) {
                f[3].push_back(mp(x, -y));
            }
        }
        for (int j = 0; j < 4; j++) {
            sort(f[j].begin(), f[j].end(), cmp);
        }
        ll tot = (n - 1) * (n - 2) * (n - 3) / 6;
        ll bad = 0;
        for (int j = 0; j < 4; j++) {
            ll sz = f[j].size();
            for (int k = 0; k < sz; k++) {
                ll one_part = f[(j+1)%4].size();
                ll pos = upper_bound(f[(j+2)%4].begin(), f[(j+2)%4].end(), f[j][k], cmp) - f[(j+2)%4].begin();
                ll sz2 = f[(j+2)%4].size();
                if (j % 2 == 0) {
                    one_part += k + sz2 - pos;
                } else {
                    one_part += sz - k - 1 + pos;
                }
                //cout << "x " << one_part << " " << one_part * (one_part - 1) / 2 + (n - 2 - one_part) * (n - 2 - one_part -1) / 2 << "\n";
                bad += one_part * (one_part - 1) / 2 + (n - 2 - one_part) * (n - 2 - one_part -1) / 2;
            }
        }
        ans += (tot - bad / 2);
        //cout << tot << " " << bad << "\n";
    }
    cout << ans * (n - 4) / 2 << "\n";
    return 0;

}