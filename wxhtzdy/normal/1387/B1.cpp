#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<vector<int>> g(N);
vector<int> ans(N);
int cnt = 0;

void Dfs(int v, int p) {
    for (auto c : g[v]) {
        if (c == p) {
            continue;
        }
        if (ans[c] == c) {
            Dfs(c, v);
            if (ans[c] == c) {
                cnt += 2;
                swap(ans[v], ans[c]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        ans[i] = i;
    }
    Dfs(0, -1);
    if (ans[0] == 0) {
        cnt += 2;
        swap(ans[0], ans[g[0][0]]);
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}