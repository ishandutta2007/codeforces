#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int vis[MN], N, i, cost[MN], f[MN], in[MN], ans, st[MN];
stack<int> s;
void dfs(int n){
    int mn=cost[n]; vis[n]=1;
    s.push(n); st[n] = 1;
    if(vis[f[n]]&&st[f[n]]){
        while(s.size()){
            int c=s.top(); s.pop();
            st[c]=0; mn=min(mn,cost[c]);
            if(c == f[n]) break;
        }
        ans += mn;
    }
    else if(!vis[f[n]]) dfs(f[n]);
    if(st[n]) s.pop(), st[n]=0;
}
int main(){
    for(scanf("%d",&N),i=1;i<=N;i++)
        scanf("%d",&cost[i]);
    for(i=1;i<=N;i++)
        scanf("%d",&f[i]);
    for(i=1;i<=N;i++){
        if(!vis[i]) dfs(i);
    }
    printf("%d\n",ans);
    return 0;
}