#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[210000],p[210000],len,n;
struct bian{
    int next,point;
}b[210000];
long long dp[210000][2];
void add(int k1,int k2){
    b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void dfs(int k){
    dp[k][1]=-1e18; dp[k][0]=0;
    for (int i=p[k];i;i=b[i].next){
        int j=b[i].point; dfs(j); 
    }
    for (int i=p[k];i;i=b[i].next){
        int j=b[i].point;
        long long k1=dp[k][1],k2=dp[k][0];
        dp[k][1]=max(dp[k][1],max(k1+dp[j][0],k2+dp[j][1]));
        dp[k][0]=max(dp[k][0],max(k1+dp[j][1],k2+dp[j][0]));
    }
    dp[k][1]=max(dp[k][0]+w[k],dp[k][1]);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int k1; scanf("%d%d",&k1,&w[i]);
        if (i!=1) add(k1,i);
    }
    dfs(1);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}