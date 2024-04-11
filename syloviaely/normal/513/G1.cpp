#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long double dp[31][31],f[31][31];
int n,k,x[31],A[31];
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) dp[i][j]=(x[i]>x[j]);
    int tot=(n+1)*n/2;
    for (;k;k--){
        memset(f,0x00,sizeof f);
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++){
                for (int k1=1;k1<=n;k1++) A[k1]=k1;
                for (int k1=i,k2=j;k1<k2;k1++,k2--){
                    A[k1]=k2; A[k2]=k1;
                }
                for (int k1=1;k1<=n;k1++)
                    for (int k2=k1+1;k2<=n;k2++)
                        if (A[k1]<A[k2]) f[A[k1]][A[k2]]+=dp[k1][k2]/tot; else f[A[k2]][A[k1]]+=(1-dp[k1][k2])/tot;
            }
        memcpy(dp,f,sizeof f);
    }
    long double ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) ans+=dp[i][j];
    printf("%.11lf\n",(double)ans);
    return 0;
}