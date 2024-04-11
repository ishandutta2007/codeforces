#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> par(n);
        vector<vector<int>> g(n);
        int rt = -1;
        for(int i = 0; i < n; ++i) {
            cin >> par[i];
            --par[i];
            if(i == par[i]) rt = i;
            else g[par[i]].push_back(i);
        }
        vector<int> rk(n);
        for(int i = 0; i < n; ++i) cin >> rk[i], --rk[i];
        vector<int> dfn(n); int tot = 0;
        set<int> q;
        q.insert(rt);
        int cur = 0, ok = 1;
        while(cur < n) {
            if(!q.count(rk[cur])) {
                ok = 0;
                break;
            }
            int u = rk[cur++];
            dfn[u] = tot++;
            for(int v : g[u]) {
                q.insert(v);
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        for(int i = 0; i < n; ++i) {
            if(i == rt) cout << 0 << " ";
            else cout << dfn[i] - dfn[par[i]] << " ";
        }
        cout << '\n';
    }
}