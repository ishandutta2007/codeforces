#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,a,b,dp[6000][6000],mo=1e9+7,A[6000],B[6000];
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&k);
    if (a>b){
        a=n-a+1; b=n-b+1;
    }
    dp[0][a]=1;
    for (int i=1;i<b;i++)
        for (int j=i;j<b;j++) if (abs(j-i)<abs(b-j)) A[i]=j;
    for (int i=1;i<=k;i++){
        int sum=0;
        for (int j=1;j<b;j++){
            for (int k1=A[j-1]+1;k1<=A[j];k1++) sum=(sum+dp[i-1][k1])%mo;
            dp[i][j]=sum;
        }
        for (int j=1;j<b;j++) dp[i][j]=(dp[i][j]-dp[i-1][j]+mo)%mo;
    }
    int ans=0;
    for (int i=1;i<b;i++) ans=(ans+dp[k][i])%mo;
    cout<<ans<<endl; return 0;
}