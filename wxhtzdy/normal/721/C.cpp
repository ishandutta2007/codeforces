#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=5050;
const ll inf=1e16;
int n,m,t,in[N],tsz;
ll dp[N][N];
bool was[N];
vector<pair<int,int>> E[N];
void DFS(int u){
    was[u]=true;
    for(auto e:E[u]){
        if(!was[e.first])DFS(e.first);
        for(int i=2;i<=n;i++)dp[u][i]=min(dp[u][i],dp[e.first][i-1]+e.second);
    }
}
void Rec(int u,int cnt){
    printf("%i ",u);
    for(auto e:E[u]){
        if(dp[u][cnt]==dp[e.first][cnt-1]+e.second){
            Rec(e.first,cnt-1);
            return;
        }
    }
}
int main(){
    scanf("%i%i%i",&n,&m,&t);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%i%i%i",&u,&v,&w);
        E[u].pb({v,w});
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=inf;
    dp[n][1]=0;
    DFS(1);
    int ans=1;
    for(int i=1;i<=n;i++)if(dp[1][i]<=t)ans=i;
    printf("%i\n",ans);
    Rec(1,ans);
    return 0;
}