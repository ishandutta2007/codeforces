#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, ans = 0, a[200010];
map<int, int> dp[200010];
vector<int> path[200010];

vector<int> factor(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) ret.push_back(n);
    return ret;
}

void dfs(int v, int par) {
    for (int sv : path[v]) {
        if (sv == par) continue;
        dfs(sv, v);
    }

    vector<int> primes = factor(a[v]);

    for (int p : primes) {
        vector<int> child = {0, 0};
        for (int sv : path[v]) {
            if (sv == par) continue;
            if (dp[sv].count(p)) {
                child.push_back(dp[sv][p]);
            }
        }

        sort(child.rbegin(), child.rend());
        ans = max(ans, child[0] + child[1] + 1);
        dp[v][p] = child[0] + 1;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    dfs(0, -1);
    cout << ans << endl;
    return 0;
}