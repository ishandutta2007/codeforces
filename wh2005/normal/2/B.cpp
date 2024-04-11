#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
int n,a[N][N],xz,yz,flag;
struct pp{int num2,num5;}dp[N][N],g[N][N],op[N][N];
int cont(int x,int y){
    int t=0;while(x%y==0&&x){x/=y,t++;}return t;
}
void dfs(int x,int y,int opt){
    if(x==1&&y==1) return ;
    if(opt==2){
        if(op[x][y].num2==1){
            dfs(x-1,y,opt);
            printf("D");
        }
        if(op[x][y].num2==2){
            dfs(x,y-1,opt);
            printf("R");
        }
    }
    if(opt==5){
        if(op[x][y].num5==1){
            dfs(x-1,y,opt);
            printf("D");
        }
        if(op[x][y].num5==2){
            dfs(x,y-1,opt);
            printf("R");
        }
    }
    return ;
}
int main(){
    scanf("%d",&n);flag=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){xz=i,yz=j,flag=1;}
            g[i][j].num2=cont(a[i][j],2);
            g[i][j].num5=cont(a[i][j],5);
        }
    dp[1][1].num2=g[1][1].num2;
    dp[1][1].num5=g[1][1].num5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) continue;
            dp[i][j].num2=dp[i][j].num5=2e9;
            if(i>1&&dp[i][j].num2>dp[i-1][j].num2) dp[i][j].num2=dp[i-1][j].num2,op[i][j].num2=1;
            if(i>1&&dp[i][j].num5>dp[i-1][j].num5) dp[i][j].num5=dp[i-1][j].num5,op[i][j].num5=1;
            if(j>1&&dp[i][j].num2>dp[i][j-1].num2) dp[i][j].num2=dp[i][j-1].num2,op[i][j].num2=2;
            if(j>1&&dp[i][j].num5>dp[i][j-1].num5) dp[i][j].num5=dp[i][j-1].num5,op[i][j].num5=2;
            dp[i][j].num2+=g[i][j].num2,dp[i][j].num5+=g[i][j].num5;
        }
    }
    int ans=min(dp[n][n].num2,dp[n][n].num5);
    if(ans>1&&flag==1){
        printf("1\n");
        for(int i=1;i<xz;i++) printf("D");
        for(int i=1;i<yz;i++) printf("R");
        for(int i=xz;i<n;i++) printf("D");
        for(int i=yz;i<n;i++) printf("R");
        puts("");
    }
    else{
        printf("%d\n",ans);
        int opt=(dp[n][n].num5>dp[n][n].num2)?2:5;
        dfs(n,n,opt);
    }
    return 0;
}