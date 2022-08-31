#include<bits/stdc++.h>
using namespace std;

int t;
vector<int> adj[200005];
int deg[200005],a[200005];

signed main(){
    cin >> t;
    while(t --){
        int n; cin >> n;
        for(int i = 1; i <= n; i ++){
            deg[i] = 0;
            adj[i].clear();
            cin >> a[i];
        }
        for(int i = 0; i < n-1; i ++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans1 = 1,ans2 = 1;
        queue<int> q[3];
        // start with 1---------------------------------------
        for(int i = 1; i <= n; i ++) deg[i] = adj[i].size();
        for(int i = 1; i <= n; i ++){
            if(deg[i] == 1) q[a[i]].push(i);
        }
        int cur = 1;
        while(!q[0].empty() or !q[1].empty() or !q[2].empty()){
            if(q[cur].empty() and q[0].empty()){
                cur = 3-cur;
                ans1++;
            }
            int u;
            if(q[cur].empty()){
                u = q[0].front();
                q[0].pop();
            }
            else{
                u = q[cur].front();
                q[cur].pop();
            }
            
            deg[u] = 0;
            for(auto v:adj[u]){
                deg[v]--;
                if(deg[v] == 1){
                    q[a[v]].push(v);
                }
            }
        }
        // ---------------------------------------------------
        // start with 2---------------------------------------
        for(int i = 1; i <= n; i ++) deg[i] = adj[i].size();
        for(int i = 1; i <= n; i ++){
            if(deg[i] == 1) q[a[i]].push(i);
        }
        cur = 2;
        while(!q[0].empty() or !q[1].empty() or !q[2].empty()){
            if(q[cur].empty() and q[0].empty()){
                cur = 3-cur;
                ans2++;
            }
            int u;
            if(q[cur].empty()){
                u = q[0].front();
                q[0].pop();
            }
            else{
                u = q[cur].front();
                q[cur].pop();
            }
            
            deg[u] = 0;
            for(auto v:adj[u]){
                deg[v]--;
                if(deg[v] == 1){
                    q[a[v]].push(v);
                }
            }
        }
        // ---------------------------------------------------
        cout << min(ans1,ans2) << "\n";
    }
}