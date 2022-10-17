#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    vector<int> pre(n, -1), vis(n);
    int cnt = 0;
    vector<int> pa, pb; int fd = 0;
    for(int t : g[s]) {
        ++cnt;
        function<void(int)> dfs = [&](int u) {
            vis[u] = cnt;
            for(int v : g[u]) {
                if(v == s) continue;
                if(vis[v]) {
                    if(vis[v] == cnt) continue;
                    int p = v; while(p != s) pa.push_back(p), p = pre[p]; pa.push_back(s);
                    pb.push_back(v); p = u; while(p != s) pb.push_back(p), p = pre[p]; pb.push_back(s);
                    fd = 1; return;
                }
                pre[v] = u;
                dfs(v);
                if(fd) return;
            }
        };
        if(vis[t]) {
            int v = t;
            int p = v; while(p != s) pa.push_back(p), p = pre[p]; pa.push_back(s);
            pb.push_back(v); pb.push_back(s);
            fd = 1; break;
        }
        pre[t] = s;
        dfs(t);
        if(fd) break;
    }
    if(fd) {
        cout << "Possible\n";
        reverse(pa.begin(), pa.end());
        reverse(pb.begin(), pb.end());
        cout << pa.size() << '\n'; for(int u : pa) cout << u + 1 << " "; cout << '\n';
        cout << pb.size() << '\n'; for(int u : pb) cout << u + 1 << " "; cout << '\n';
    } else {
        cout << "Impossible\n";
    }
}