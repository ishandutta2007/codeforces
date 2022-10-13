#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
vector<int> adj[MX];
int par[MX];
bool visited[MX];
vector<int> inCycle;
bool found;
void dfs(int curr) {
    if(found) return;
    for(int next : adj[curr]) {
        if(found) return;
        if(par[next]!=-1) { //check ikf this works
            if(next!=par[curr]) {
                //checmk if this work
                found = true;
                int temp = curr;
                while(temp!=next) {
                    inCycle.push_back(temp);
                    temp = par[temp];
                }
                inCycle.push_back(next);
                return;
            }
        }
        else {
            par[next] = curr;
            dfs(next);
        }
        
    }
}
int dfs2(int curr) {
    visited[curr] = true;
    int ret = 1;
    for(int next : adj[curr]) {
        if(!visited[next]) {
            ret+=dfs2(next);
        }
    }
    return ret;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=0;i<n;i++) {
            adj[i].clear();
            par[i] = -1;
        }
        found = false;
        inCycle.clear();
        for(int i=0;i<n;i++) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v), adj[v].push_back(u);
        }
        par[0] = 0;
        dfs(0);
        for(int i=0;i<n;i++) {
            visited[i] = false;
        }
        for(auto &it : inCycle) visited[it] = 1;
        ll sumsq = 0;
        for(auto &it : inCycle) {
            int x = dfs2(it);
            sumsq-=x*1LL*x;
        }
        sumsq+=2*1LL*n*1LL*n;
        sumsq-=n;
        cout << sumsq/2 << "\n";
    }
}