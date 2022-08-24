#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,nI[110000],I[110000],n,m;
char ch[110000];
int quick(int k1,int k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2>>=1;
    }
    return k3;
}
int C(int k1,int k2){
    if (k2>k1) return 0;
    return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int main(){
    scanf("%d%d",&n,&m); scanf("%s",ch+1);
    if (m==0){
        int ans=0;
        for (int i=1;i<=n;i++) ans=(1ll*ans*10+ch[i]-'0')%mo;
        cout<<ans<<endl; return 0;
    }
    for (int i=1;i<=n;i++) nI[i]=quick(i,mo-2); nI[0]=1;
    for (int i=1;i<=n;i++) nI[i]=1ll*nI[i]*nI[i-1]%mo;
    I[0]=1; for (int i=1;i<=n;i++) I[i]=1ll*I[i-1]*i%mo;
    int ans=0,num=0,pre=1;
    for (int i=n;i;i--){
        int k1=(num+1ll*pre*C(i-1,m))%mo;
        ans=(ans+1ll*k1*(ch[i]-'0'))%mo;
        num=(num+1ll*pre*C(i-2,m-1))%mo; pre=1ll*pre*10%mo;
    }
    cout<<ans<<endl;
    return 0;
}