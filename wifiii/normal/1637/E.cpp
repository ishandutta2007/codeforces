#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll val; int x1, y1, x2, y2;
    bool operator < (const node & n) const {
        return val < n.val;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        map<pair<int,int>, int> bad;
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            bad[{u, v}] = 1;
        }
        vector<int> vis(n);
        map<int, int> mp;
        for(int i : a) mp[i] += 1;
        vector<vector<int>> b(n);
        vector<int> c;
        for(auto [x, y] : mp) {
            if(!vis[y]) c.push_back(y);
            vis[y] = 1;
            b[y].push_back(x);
        }
        for(int i : c) {
            sort(b[i].begin(), b[i].end(), greater<int>());
        }
        int k = c.size();
        priority_queue<node> q;
        for(int i : c) {
            for(int j : c) {
                if(i <= j) {
                    int x1 = i, y1 = 0, x2 = j, y2 = 0;
                    ll val = 1ll * (b[x1][y1] + b[x2][y2]) * (x1 + x2);
                    q.push({val, x1, y1, x2, y2});
                }
            }
        }
        ll ans = -1;
        map<pair<int,int>, int> d;
        while(!q.empty()) {
            auto [v, x1, y1, x2, y2] = q.top(); q.pop();
            int id1 = b[x1][y1], id2 = b[x2][y2];
            if(id1 > id2) swap(id1, id2);
            if(id1 != id2 && !bad.count({id1, id2})) {
                ans = v;
                break;
            }
            if(d.count({id1, id2})) continue;
            d[{id1, id2}] = 1;
            if(y2 + 1 < b[x2].size()) {
                ll val = 1ll * (b[x1][y1] + b[x2][y2 + 1]) * (x1 + x2);
                q.push({val, x1, y1, x2, y2 + 1});
            }
            if(y1 + 1 < b[x1].size()) {
                ll val = 1ll * (b[x1][y1 + 1] + b[x2][y2]) * (x1 + x2);
                q.push({val, x1, y1 + 1, x2, y2});
            }
        }
        cout << ans << '\n';
    }
}