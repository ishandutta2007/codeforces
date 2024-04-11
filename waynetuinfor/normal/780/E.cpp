#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
vector<int> G[maxn], euler;
bool v[maxn];

void dfs(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    int ind = 0;
    for (int i = 0; i < k; ++i) {
        int cnt = ceil((double)((int)euler.size() - ind) / (double)(k - i));
        cout << cnt << ' ';
        for (int j = 0; j < cnt; ++j, ++ind) cout << euler[ind] << ' '; cout << '\n';
    }
    return 0;
}

void dfs(int x) {
    v[x] = true;
    euler.push_back(x);
    for (int u : G[x]) {
        if (!v[u]) dfs(u), euler.push_back(x);
    }
}