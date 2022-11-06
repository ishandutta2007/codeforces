#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn], vec;
double ans[maxn];

void dfs(int now, int fa, double d, int l) {
    ans[now] = d * (double)l;
    int ch = 0;
    for (int u : G[now]) if (u != fa) ++ch;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d / (double)ch, l + 1);
    }
    if (ch == 0) vec.push_back(now);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, 1.0, 0);
    double a = 0.0;
    for (int i : vec) a += ans[i];
    cout << fixed << setprecision(20) << a << endl;
}