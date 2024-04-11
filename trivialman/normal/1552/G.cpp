#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 45;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k, m, a[N];
bool v[N];
LL mask[N];
vector<LL> f, g;

int main() {
    cin >> n >> k;
    f.PB(0);
    while (k--) {
        cin >> m;
        g.clear(), mask[m] = 0;
        LL cnt_new = 0, mask_new = 0;

        rep(i, 1, m) {
            cin >> a[i], mask[m] |= 1ll << a[i];
            if (!v[a[i]])
                cnt_new++, mask_new |= 1ll << a[i];
        }
        rrep(i, m - 1, 0) mask[i] = mask[i + 1] - (mask[i + 1] & -mask[i + 1]);

        g.resize(f.size() * (cnt_new + 1));
        LL tmp = mask_new, tot = 0;
        rep(n1, 0, cnt_new) {
            for (LL ele : f) {
                ele |= tmp;
                int x = __builtin_popcountll(ele & mask[m]);
                ele = ele & ~mask[m];
                ele = ele | mask[x];
                g[tot++] = ele;
            }
            tmp -= tmp & -tmp;
        }

        rep(i, 1, m) v[a[i]] = true;
        swap(f, g);
    }

    bool ac = true;
    rep(i, 1, n) if (!v[i]) ac = false;
    for (LL x : f) {
        x = x + (x & -x);
        if (x != (1ll << n + 1) && x != 0) {
            ac = false;
            break;
        }
    }
    ac |= n == 1;
    cout << (ac ? "ACCEPTED" : "REJECTED");
    return 0;
}