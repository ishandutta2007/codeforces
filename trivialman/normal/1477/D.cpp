#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 5e5 + 5;
mt19937 rng(time(0));

vector<int> g[N], g2[N];
int group[N], gsize[N], p[N], q[N];
bool v[N];
int T, n, m, x, y;

int main() {
    cin >> T;
    rep(cas, 1, T) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) g[i].clear(), g2[i].clear();

        rep(i, 1, m) {
            scanf("%d%d", &x, &y);
            g[x].PB(y), g[y].PB(x);
        }

        rep(i, 1, n) group[i] = gsize[i] = 0;
        rep(i, 1, n) if (!group[i]) {
            if (g[i].size() == n - 1) {
                group[i] = i, gsize[i] = 1;
                continue;
            }

            int x;
            for (auto u : g[i])
                v[u] = true;
            rep(u, 1, n) if (u != i && !v[u]) {
                x = u;
                break;
            }
            for (auto u : g[i])
                v[u] = false;
            
            if (!group[x] || group[x] == x)
                group[i] = group[x] = x, gsize[x] = gsize[x] ? gsize[x] + 1 : 2;
            else {
                int y = group[x];
                if (gsize[y] == 2) {
                    group[y] = group[x] = group[i] = x;
                    gsize[y] = 0, gsize[x] = 3;
                } else {
                    group[i] = group[x] = i;
                    gsize[i] = 2, gsize[y]--;
                }
            }
        }

        rep(i, 1, n) if (group[i] != i) g2[group[i]].PB(i);

        int num = 1;
        rep(i, 1, n) if (gsize[i]) {
            int sz = gsize[i];
            if (sz == 1)
                p[i] = q[i] = num++;
            else {
                rep(j, 0, sz - 2)
                    p[g2[i][j]] = num + j + 1,
                    q[g2[i][j]] = num + j;
                p[i] = num, q[i] = num + sz - 1;
                num += sz;
            }
        }
        rep(i, 1, n) printf("%d%c", p[i], i < n ? ' ' : '\n');
        rep(i, 1, n) printf("%d%c", q[i], i < n ? ' ' : '\n');
    }
    return 0;
}