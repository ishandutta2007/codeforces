#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
int dp[30100][610],lim=250,x[30100],n,d;
unordered_map<int,int>M[100100];
int findans(int k1,int k2){
    if (k1>30000) return 0;
    int k3=M[k1][k2];
    if (k3!=0) return k3-1;
    int ans=0;
    for (int i=k2-1;i<=k2+1;i++) if (i) ans=max(ans,findans(k1+i,i));
    M[k1][k2]=ans+x[k1]+1; return ans+x[k1];
}
int main(){
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1); x[k1]++;
    }
    if (d<=lim){
        for (int i=0;i<=30000;i++)
            for (int j=0;j<=500;j++) dp[i][j]=-1e9;
        dp[d][d]=x[d];
        for (int i=0;i<=30000;i++)
            for (int j=1;j<=500;j++)
                for (int k=j-1;k<=j+1;k++)
                    if (k&&i+k<=30000) dp[i+k][k]=max(dp[i+k][k],dp[i][j]+x[i+k]);
        int ans=0;
        for (int i=0;i<=30000;i++)
            for (int j=1;j<=500;j++) ans=max(ans,dp[i][j]);
        printf("%d\n",ans); return 0;
    }
    printf("%d\n",findans(d,d));
    return 0;
}