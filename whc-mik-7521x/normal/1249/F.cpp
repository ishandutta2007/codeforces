#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,k,dp[N][N];
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int a[N];
void dfs(int x,int fa){
    dp[x][0]=a[x];
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        int temp[N];
        memset(temp,0,sizeof temp);
        for(int o=0;o<=n;o++){
            for(int j=0;j<=n;j++){
                if(o+j+1>k)temp[min(o,j+1)]=max(temp[min(o,j+1)],dp[x][o]+dp[v][j]);
            }
        }
        for(int o=0;o<=n;o++)dp[x][o]=max(dp[x][o],temp[o]);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[1][i]);
    }
    cout<<ans;
    return  0;
}