#include <bits/stdc++.h>
using namespace std;

const int MN = 210;
int f[MN][MN], st[MN], en[MN], p[MN], n, m, i, j, x, y;
vector<int> adj[MN]; queue<int> q, src;
int bfs(int src){
    while(q.size()) q.pop();
    q.push(src); p[src]=0;
    while(q.size()){
        int cur=q.front(); q.pop();
        if(cur>n&&en[cur]) return cur;
        for(auto v : adj[cur]){
            if(p[v]==-1&&f[cur][v]>0){
                p[v] = cur;
                q.push(v);
            }
        }
    }
    return -1;
}
int ex_path(){
    memset(p,-1,sizeof(p));
    while(src.size()){
        int cur = src.front(); src.pop();
        int tmp = bfs(cur);
        if(tmp!=-1) return tmp;
    }
    return -1;
}
int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
        scanf("%d",&st[i]);
    for(i=1;i<=n;i++){
        scanf("%d",&en[i+n]);
        adj[i].push_back(i+n);
        adj[i+n].push_back(i);
        src.push(i);
    }
    for(i=1;i<=n;i++){
        for(j=n+1;j<=2*n;j++)
            f[i][j] = 1<<30;
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y+n);
        adj[y+n].push_back(x);
        adj[y].push_back(x+n);
        adj[x+n].push_back(y);
    }
    x = ex_path();
    while(x != -1){
        int last = x, fl = en[last];
        while(1){
            if(p[x] == 0){
                fl = min(fl, st[x]);
                break;
            }
            fl = min(fl, f[p[x]][x]);
            x = p[x];
        }
        x = last; en[last] -= fl;
        while(1){
            if(p[x] == 0){
                st[x] -= fl;
                if(st[x]) src.push(x);
                break;
            }
            f[p[x]][x] -= fl;
            f[x][p[x]] += fl;
            x = p[x];
        }
        x = ex_path();
    }
    bool d = 0;
    for(i=1;i<=n;i++){
        if(st[i]||en[i+n]) d=1;
    }
    if(d) printf("NO\n");
    else{
        printf("YES\n");
        for(i=1;i<=n;i++){
            for(j=n+1;j<=2*n;j++){
                printf("%d ",f[j][i]);
            }
            printf("\n");
        }
    }
}