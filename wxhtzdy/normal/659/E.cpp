#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
vector<int> E[N];
bool was[N];
int ok;
void DFS(int u,int p){
    was[u]=1;
    for(int v:E[u]){
        if(v==p)continue;
        if(!was[v])DFS(v,u);
        else ok=0;
    }
}
int main(){
    int n,m;scanf("%i %i",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;scanf("%i %i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!was[i])ok=1,DFS(i,-1),ans+=ok;
    }
    printf("%i",ans);
    return 0;
}