#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=205;
vector<pair<int,int>> E[N];
bool was[N];
int dist[N];
void DFS(int u,int p,int i){
    was[u]=true;
    for(auto e:E[u]){
        if(e.first!=p&&e.second!=i){
            dist[e.first]=dist[u]+1;
            DFS(e.first,u,i);
        }
    }
}
void DFS1(int u,int p,int i){
    dist[u]=0;
    for(auto e:E[u])if(e.first!=p&&e.second!=i)DFS1(e.first,u,i);
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i%i",&u,&v);
        E[u].pb({v,i});
        E[v].pb({u,i});
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++)was[j]=false,dist[j]=0;
        int res=1;
        for(int j=1;j<=n;j++){
            if(was[j])continue;
            DFS(j,j,i);
            int mx=j;
            for(int x=1;x<=n;x++)if(dist[x]>dist[mx])mx=x;
            dist[mx]=0;
            DFS(mx,mx,i);
            for(int x=1;x<=n;x++)if(dist[x]>dist[mx])mx=x;
            res*=max(0,dist[mx]);
            DFS1(mx,mx,i);
        }
        ans=max(ans,res);
    }
    printf("%i\n",ans);
    return 0;
}