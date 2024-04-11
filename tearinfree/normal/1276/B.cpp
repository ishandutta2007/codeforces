#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,vis[200001][2];
vector<int> adj[200001];

void bfs(int cur,int idx) {
    queue<int> que;
    que.push(cur);
    while(!que.empty()) {
        int cur=que.front();que.pop();
        for(auto &it:adj[cur]) if(it!=a && it!=b && !vis[it][idx]) {
            que.push(it);
            vis[it][idx] = 1;
        }
    }
}
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i=0,u,v;i<m;i++) {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++) memset(vis[i],0,sizeof(vis[i]));
        bfs(a,0);
        bfs(b,1);

        int ac=0,bc=0;
        for(int i=1;i<=n;i++) if(i!=a && i!=b && !(vis[i][0] && vis[i][1])) {
            if(vis[i][0]) ac++;
            else bc++;
        }
        printf("%lld\n",1ll*ac*bc);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
    
    return 0;
}