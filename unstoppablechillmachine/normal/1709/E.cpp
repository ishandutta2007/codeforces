#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 2e5 + 10;
int a[N], push_xor[N], answer = 0;
vector<int> g[N];
set<int> have[N];

void dfs(int v, int parent = 0) {
    vector<pair<int, int>> children;
    for (auto u : g[v]) {
        if (u != parent) {
            dfs(u, v);
            if (!have[u].empty()) {
                children.emplace_back(have[u].size(), u);
            }
        }
    }

    sort(children.rbegin(), children.rend());

    if (children.empty()) {
        have[v] = {0};
        push_xor[v] = a[v];
    } else {
        bool bad = false;
        have[v].swap(have[children[0].second]);
        if (have[v].count(a[v] ^ push_xor[children[0].second])) {
            bad = true;
        }
        have[v].insert(push_xor[children[0].second]);
        push_xor[v] = push_xor[children[0].second] ^ a[v];
        

        for (int i = 1; i < children.size(); i++) {
            int u = children[i].second;
            for (auto val : have[u]) {
                if (have[v].count(val ^ push_xor[u] ^ push_xor[v])) {
                    bad = true;
                    break;
                }
            }
            for (auto val : have[u]) {
                int true_val = val ^ push_xor[u] ^ push_xor[children[0].second];
                have[v].insert(true_val);
            }
        }

        if (bad) {
            have[v] = {};
            answer++;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << answer << '\n';
    return 0;
}