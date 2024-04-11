#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

#define int ll
int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        int lo = 0, hi = n - 1;
        vector<int> p;
        vector<int> sz;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            vector<int> degx = deg;
            vector<int> del(n);
            queue<int> q;
            for(int i = 0; i < n; ++i) {
                if(degx[i] == 1 && i > mid) q.push(i);
            }
            while(!q.empty()) {
                int u = q.front(); q.pop();
                del[u] = 1;
                for(int v : g[u]) {
                    if(--degx[v] == 1 && v > mid) {
                        q.push(v);
                    }
                }
            }
            int ok = 1;
            int l = -1, r = -1;
            for(int i = 0; i < n; ++i) {
                if(degx[i] > 2) {
                    ok = 0;
                    break;
                }
                if(degx[i] == 1) {
                    if(l == -1) l = i;
                    else r = i;
                }
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        vector<ll> ans(n + 1);
        {
            vector<int> degx = deg;
            vector<int> del(n);
            queue<int> q;
            for(int i = 0; i < n; ++i) {
                if(degx[i] == 1 && i > lo) q.push(i);
            }
            while(!q.empty()) {
                int u = q.front(); q.pop();
                del[u] = 1;
                for(int v : g[u]) {
                    if(--degx[v] == 1 && v > lo) {
                        q.push(v);
                    }
                }
            }
            int ok = 1;
            int l = -1, r = -1;
            for(int i = 0; i < n; ++i) {
                if(del[i]) continue;
                if(degx[i] > 2) {
                    ok = 0;
                    break;
                }
                if(degx[i] == 1) {
                    if(l == -1) l = i;
                    else r = i;
                }
            }
            assert(ok);
            queue<int> qwq;
            vector<int> vis(n);
            qwq.push(l);
            vis[l] = 1;
            while(!qwq.empty()) {
                int u = qwq.front(); qwq.pop();
                p.push_back(u);
                for(int v : g[u]) {
                    if(del[v] || vis[v]) continue;
                    qwq.push(v);
                    vis[v] = 1;
                }
            }
            fill(vis.begin(), vis.end(), 0);
            for(int x : p) {
                queue<int> qaq;
                qaq.push(x);
                vis[x] = 1;
                int cnt = 0;
                while(!qaq.empty()) {
                    int u = qaq.front(); qaq.pop();
                    cnt += 1;
                    for(int v : g[u]) {
                        if(!del[v] || vis[v]) continue;
                        vis[v] = 1;
                        qaq.push(v);
                    }
                }
                sz.push_back(cnt);
            }
            ll wtf = 0;
            int cnt = 0;
            function<void(int,int)> dfs = [&](int u, int fa) {
                cnt += 1;
                for(int v : g[u]) {
                    if(v == fa) continue;
                    dfs(v, u);
                }
            };
            int sum = 1;
            for(int v : g[0]) {
                cnt = 0;
                dfs(v, 0);
                ans[0] += 1ll * cnt * (cnt - 1) / 2;
                sum += cnt;
            }
        }
        vector<int> pre(p.size()+1),rpos(n+1);
        for(int i=0;i<p.size();++i) {
            pre[i+1]=pre[i]+sz[i];
            rpos[p[i]]=i;
        }
        int l=rpos[0],r=rpos[0];
        for(int i=1;i<=lo;++i) {
            l=min(l,rpos[i]);
            r=max(r,rpos[i]);
            ans[i+1]=1ll*(pre.back()-pre[r])*pre[l+1];
        }
        ll tot=1ll*n*(n-1)/2;
        for(int i=2;i<=lo;++i) ans[i]-=ans[i+1];
        for(int i=0;i<=1+lo;++i) tot-=ans[i];
        ans[1]=tot;
        for(ll x : ans) cout << x << " ";
        cout << endl;
    }
}