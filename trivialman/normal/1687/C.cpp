#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int N = 2e5 + 5;

int T, n, m, l, r;
vector<int> g[N];
LL a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        rep(i, 1, n) cin >> a[i], a[i] += a[i - 1];
        rep(i, 1, n) cin >> b[i], b[i] += b[i - 1];

        set<int> neq;
        rep(i, 1, n) if (a[i] != b[i]) neq.insert(i);
        rep(i, 0, n) g[i].clear();

        queue<ar2> Q;
        rep(i, 1, m) {
            cin >> l >> r, l--;
            if (!neq.count(l) && !neq.count(r))
                Q.push({l, r});
            g[l].PB(r), g[r].PB(l);
        }

        while (!Q.empty()) {
            auto [l, r] = Q.front();
            Q.pop();
            auto itl = neq.upper_bound(l), itr = neq.upper_bound(r);
            for (auto iter = itl; iter != itr; iter++) {
                int x = *iter;
                for (auto y : g[x])
                    if (!neq.count(y))
                        Q.push({min(x, y), max(x, y)});
            }
            neq.erase(itl, itr);
        }
        cout << (!neq.size() ? "YES\n" : "NO\n");
    }
    return 0;
}