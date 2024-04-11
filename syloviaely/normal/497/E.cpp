#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct atom{
    int x[31][31];
}dp[70],B;
int K,mo=1e9+7,x[70],len,A[70];
long long n;
atom mul(atom k1,atom k2){
    memset(B.x,0x00,sizeof B.x);
    for (int i=0;i<K;i++){
        B.x[i][K]=k2.x[i][K];
        for (int j=0;j<K;j++){
            B.x[i][K]=(B.x[i][K]+1ll*k2.x[i][j]*k1.x[j][K])%mo;
            for (int k=0;k<K;k++)
                B.x[i][k]=(B.x[i][k]+1ll*k2.x[i][j]*k1.x[j][k])%mo;
        }
    }
    return B;
}
int main(){
    scanf("%I64d%d",&n,&K); len=1; x[1]=(n-1)%K; long long kk=(n-1)/K;
    while (kk){
        x[++len]=kk%K; kk/=K;
    }
    for (int j=0;j<=len;j++)
        for (int i=0;i<K;i++) dp[j].x[i][i]=1;
    for (int j=0;j<=K;j++) dp[0].x[0][j]=1;
    for (int i=1;i<=len;i++){
        for (int j=0;j<K;j++){
            atom k;     
            for (int k1=0;k1<K;k1++) A[k1]=(k1+j)%K;
            for (int k1=0;k1<K;k1++){
                k.x[A[k1]][K]=dp[i-1].x[k1][K];
                for (int k2=0;k2<K;k2++)
                    k.x[A[k1]][A[k2]]=dp[i-1].x[k1][k2];
            }
            dp[i]=mul(dp[i],k);
        }
    }
    atom ans; memset(ans.x,0x00,sizeof ans.x); 
    for (int i=0;i<K;i++) ans.x[i][i]=1;
    int pre=0; x[1]++;
    for (int i=len;i;i--){
        for (int j=0;j<x[i];j++){
            int kk=(pre+j)%K;
            atom k;     
            for (int k1=0;k1<K;k1++) A[k1]=(k1+kk)%K;
            for (int k1=0;k1<K;k1++){
                k.x[A[k1]][K]=dp[i-1].x[k1][K];
                for (int k2=0;k2<K;k2++)
                    k.x[A[k1]][A[k2]]=dp[i-1].x[k1][k2];
            }
            ans=mul(ans,k);
        }
        pre=(pre+x[i])%K;
    }
    int num=1;
    for (int i=0;i<K;i++) num=(num+ans.x[i][K])%mo; cout<<num<<endl;
    return 0;
}