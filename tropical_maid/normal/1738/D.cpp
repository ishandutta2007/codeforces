#include <bits/stdc++.h>

using namespace std;

int n;
int B[100005], D[100005];
vector<int> E[100005], ans;

void dfs(int x, int d) {
    D[x] = d;
    sort(E[x].begin(), E[x].end(), [=](int a, int b) {
        return E[a].size() < E[b].size();
    });
    for (int i : E[x]) {
        ans.push_back(i);
        dfs(i, 1 - d);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n + 1; ++i) E[i].clear();
        for (int i = 1; i <= n; ++i) {
            cin >> B[i];
            E[B[i]].push_back(i);
        }
        ans.clear();
        bool is_end = false;
        dfs(0, 0);
        if (ans.empty()) is_end = true;
        dfs(n + 1, 0);
        for (int k = is_end; k <= n; ++k) {
            if (D[k] != D[k + 1]) {
                printf("%d\n", k);
                break;
            }
        }
        for (int i : ans) printf("%d ", i);
        printf("\n");
    }
    return 0;
}