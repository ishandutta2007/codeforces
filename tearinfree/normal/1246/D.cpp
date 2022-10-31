#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,dist[100000];
vector<int> adj[100000];

int dfs(int cur) {
    for(auto &it:adj[cur]) dist[cur] = max(dist[cur], dfs(it)+1);
    return dist[cur];
}

vector<int> path, ans;
int dfs2(int cur) {
    path.push_back(cur);

    if(sz(adj[cur])==0) {
        return 1;
    }
    else {
        int md = -1, nx = -1;
        for(auto &it:adj[cur]) if(md < dist[it]) {
            md = dist[it];
            nx = it;
        }
        
        int rem = 0;
        for(auto &it:adj[cur]) if(it != nx) {
            while(rem--) ans.push_back(it);
            rem = dfs2(it);
        }
        while(rem--) ans.push_back(nx);
        rem = dfs2(nx);
        return rem + 1;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int p;
        scanf("%d",&p);
        adj[p].push_back(i);
    }
    dfs(0);
    dfs2(0);

    for(auto &it:path) printf("%d ",it);
    puts("");
    printf("%lu\n",ans.size());
    for(auto &it:ans) printf("%d ",it);
    
    return 0;
}