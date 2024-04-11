#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define PI acosl(-1)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> p(n);
        vector<int> num(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            --p[i];
            //p[i] = i - k ? k = i - p[i] % n
            ++num[(i - p[i] + n) % n];
        }
        vector<int> ans;
        for(int k = 0; k < n; k++) {
            if(num[k] >= n - 2 * m) {
                vector<vector<int>> adj(n);
                for(int i = 0; i < n; i++) {
                    int go = (i - k + n) % n;
                    if(go == p[i]) continue;
                    adj[p[i]].push_back(go);
                }
                queue<int> q;
                int num_comp = 0;
                vector<bool> vis(n, false);
                for(int i = 0; i < n; i++) {
                    if(vis[i]) continue;
                    ++num_comp;
                    vis[i] = true;
                    q.push(i);
                    while(!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        for(int next : adj[curr]) {
                            if(!vis[next])
                                vis[next] = true, q.push(next);
                        }
                    }
                }
                if(n - num_comp <= m) ans.push_back(k);
            }
        }
        cout << (int) ans.size() << " ";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
}