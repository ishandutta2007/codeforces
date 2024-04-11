#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int n, x, y, deg[N], parent[N];
bool flag = true;
bool isfib[N];
int fib[27], prefib[N];
set<int> g[N];

inline bool can_cmb(int x, int y) { return isfib[x] && isfib[y] && (prefib[x] == y || prefib[y] == x); }

int dfs(int x, int fa, int num) {
    int res = 0;
    deg[x] = 1;
    parent[x] = fa;
    for (auto u : g[x])
        if (u != fa) {
            int subres = dfs(u, x, num);
            res = max(res, subres);
            deg[x] += deg[u];
        }
    return res ? res : (deg[x] == prefib[num] || deg[x] == prefib[prefib[num]] ? x : 0);
}

int main() {
    memset(isfib, 0, sizeof isfib);
    fib[0] = fib[1] = 1;
    isfib[1] = true;
    prefib[1] = 1;
    rep(i, 2, 26) {
        fib[i] = fib[i - 1] + fib[i - 2], isfib[fib[i]] = true, prefib[fib[i]] = fib[i - 1];
        cerr << i << " " << fib[i] << endl;
    }

    cin >> n;
    rep(i, 1, n - 1) {
        scanf("%d%d", &x, &y);
        g[x].insert(y), g[y].insert(x);
    }
    queue<ar2> root;
    root.push({1, n});
    while (!root.empty()) {
        ar2 ele = root.front();
        root.pop();
        int rt = ele[0], num = ele[1];
        if (!isfib[num]) {
            flag = false;
            break;
        }

        int subrt = dfs(rt, 0, num);
        if (!subrt) {
            flag = false;
            break;
        }
        int fa = parent[subrt];
        g[subrt].erase(fa), g[fa].erase(subrt);
        if (deg[subrt] > 1)
            root.push({subrt, deg[subrt]});
        if (num - deg[subrt] > 1)
            root.push({rt, num - deg[subrt]});
        //cerr << rt << " " << deg[rt] << " " << subrt << " " << deg[subrt] << " " << (flag ? "YES" : "NO") << endl;
    }

    printf(flag ? "YES\n" : "NO\n");

    return 0;
}