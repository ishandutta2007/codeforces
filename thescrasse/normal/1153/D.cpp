// 1153D
// nodi con valore min o max dei figli, trovare max radice

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, n, m, res, check1, a, b, t[300010], dp[300010], degr[300010];
bool visited[300010];
vector<long long> adj[300010];

void dfs(int s) {
    dp[s] += 1000010;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dfs(u);
            if (t[s] == 0) {
                dp[s] += dp[u];
            } else {
                dp[s] = min(dp[s], dp[u]);
            }
        }
    }
    if (t[s] == 0 || (degr[s] == 1 && s != 1)) {
        dp[s] -= 1000010;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (i = 2; i <= n; i++) {
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
        degr[a]++;
        degr[i]++;
    }

    k = 0;
    for (i = 2; i <= n; i++) {
        if (degr[i] == 1) {
            k++;
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
    }

    visited[1] = true;
    dfs(1);

    res = k - dp[1] + 1;
    cout << res;

    return 0;
}