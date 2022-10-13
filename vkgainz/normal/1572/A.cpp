#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> in(n + 1), ans(n + 1);
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            in[i + 1] += k;
            for (int j = 0; j < k; j++) {
                int a; cin >> a;
                if (a < i + 1)
                    adj[a].push_back({i + 1, 0});
                else
                    adj[a].push_back({i + 1, 1});
            }
        }
        for (int i = 1; i <= n; i++) {
            adj[0].push_back({i, 0});
            ++in[i];
        }
        queue<int> q;
        int num_vis = 0;
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ++num_vis;
            for (auto [next, val] : adj[curr]) {
                --in[next];
                ans[next] = max(ans[next], ans[curr] + val);
                if (in[next] == 0)
                    q.push(next);
            }
        }
        if (num_vis < n + 1) {
            cout << -1 << "\n";
        }
        else {
            cout << *max_element(ans.begin(), ans.end()) + 1 << "\n";
        }
    }
    
}