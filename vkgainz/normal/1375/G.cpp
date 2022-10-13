#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 2e5;
vector<int> adj[MX];
int depth[MX]; 
int dpIn[MX][2], dpOut[MX][2]; // a, b (dp[a] = dp[c]?)
int ans[MX];
void dfs(int curr, int par) {
    for(int next : adj[curr]) if(next!=par) {
        depth[next] = depth[curr]+1;
        dfs(next, curr);
        dpIn[curr][0]+=dpIn[next][1];
        dpIn[curr][1]+=dpIn[next][0]+1;
    }
}
void dfs2(int curr, int par) {
    for(int next : adj[curr]) if(next!=par) {
        dpOut[next][0] = dpOut[curr][1]+dpIn[curr][1]-(dpIn[next][0]+1); //???
        dpOut[next][1] = dpOut[curr][0]+dpIn[curr][0]-(dpIn[next][1])+1; //???
        dfs2(next, curr);
    }
}
int main() {
    int n; cin >> n;
    for(int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0,-1);
    //for(int i=0;i<n;i++) cout << dpIn[i][0] << " " << dpIn[i][1] << "\n";
    //cout << "\n";
    //for(int i=0;i<n;i++) cout << dpOut[i][0] << " " << dpOut[i][1] << "\n";
    int ans = 1000000000;
    for(int i=0;i<n;i++) {
        ans = min(ans, dpOut[i][0]+dpIn[i][0]);
    }
    cout << ans << endl;
}