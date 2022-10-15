#include<bits/stdc++.h>
using namespace std;

const int maxn=1<<17;
int dp[maxn][20][2][2];
bool vis[maxn];
int n,k;

tuple<int,int,int> solve(int u,int v,int w,int z,int r1,int r2,int r3){
    int res1=r1?u:v, can1=r1?v:u, can2=r2?w:z, res2=r3?can1:can2;
    return {res1,res2,(u|v)+(w|z)+(can1|can2)};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for (int i=0;i<maxn;++i) for (int j=0;j<20;++j) for (int k=0;k<2;++k) for (int w=0;w<2;++w) dp[i][j][k][w]=-1e9;
    for (int i=0;i<k;++i) {int u; cin>>u, vis[u-1]=1;}
    for (int i=0;i<(1<<n);i+=2){
        if (vis[i]&&vis[i+1]) dp[i][1][1][1]=1;
        if ((vis[i]&&!vis[i+1])||(!vis[i]&&vis[i+1])) dp[i][1][1][0]=dp[i][1][0][1]=1;
        if (!vis[i]&&!vis[i+1]) dp[i][1][0][0]=0;
    }
    for (int i=2;i<=n;++i){
        for (int j=0;j<(1<<n);j+=(1<<i)){
            int md=j+(1<<(i-1));
            for (int u=0;u<2;++u) for (int v=0;v<2;++v) for (int w=0;w<2;++w) for (int z=0;z<2;++z) for (int r1=0;r1<2;++r1) for (int r2=0;r2<2;++r2) for (int r3=0;r3<2;++r3){
                int a,b,c;
                tie(a,b,c)=solve(u,v,w,z,r1,r2,r3);
                dp[j][i][a][b]=max(dp[j][i][a][b],dp[j][i-1][u][w]+dp[md][i-1][v][z]+c);
            }
        }
    }
    cout<<max(dp[0][n][0][0],max(dp[0][n][0][1],max(dp[0][n][1][0],dp[0][n][1][1]))+1);
    return 0;
}