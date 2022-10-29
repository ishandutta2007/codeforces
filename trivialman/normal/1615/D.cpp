#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int INF = (1 << 30) - 1;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, m, x, y, z;
int a[N], b[N], v[N], val[N];
vector<ar2> g[N];
bool flag;

void dfs(int x, int fa) {
    for (ar2 ele : g[x]) {
        int u = ele[0], par = ele[1];
        if (val[u] == -1) {
            val[u] = par ? 1 - val[x] : val[x];
            dfs(u, x);
        } else {
            if (val[u] != (par ? 1 - val[x] : val[x]))
                flag = false;
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) g[i].clear(), val[i] = -1;

        rep(i, 1, n - 1) {
            scanf("%d%d%d", a + i, b + i, v + i);
            if (v[i] >= 0) {
                int x = __builtin_popcount(v[i]) % 2;
                g[a[i]].PB({b[i], x}), g[b[i]].PB({a[i], x});
            }
        }
        rep(i, 1, m) {
            scanf("%d%d%d", &x, &y, &z);
            g[x].PB({y, z}), g[y].PB({x, z});
        }

        flag = true;
        rep(i, 1, n) if (val[i] == -1) {
            val[i] = 0, dfs(i, 0);
        }

        if (!flag)
            printf("NO\n");
        else {
            printf("YES\n");
            rep(i, 1, n - 1) {
                if (v[i] == -1)
                    v[i] = val[a[i]] ^ val[b[i]];
                printf("%d %d %d\n", a[i], b[i], v[i]);
            }
        }
    }
    return 0;
}