#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 300005;
int par[maxn];
int find(int x) {
    if(x != par[x]) return par[x] = find(par[x]);
    return x;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), nxt(n + 1), vis(n + 1), dis(n + 1);
    vector<pair<int,int>> pre(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i], par[i] = i;
    for(int i = 1; i <= n; ++i) cin >> b[i];
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = u - a[u]; i < u; i = find(i)) {
            int v = i + b[i];
            if(!vis[v]) {
                pre[v] = {i, u};
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
            par[i] = find(i + 1);
        }
    }
    if(!vis[0]) cout << -1 << endl;
    else {
        cout << dis[0] << '\n';
        vector<int> ans;
        int p = 0;
        while(p != n) {
            ans.push_back(pre[p].first);
            p = pre[p].second;
        }
        reverse(ans.begin(), ans.end());
        for(int i : ans) cout << i << " "; cout << endl;
    }
}