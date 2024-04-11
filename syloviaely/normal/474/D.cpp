#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,f[101000],n,t,k;
int main(){
    scanf("%d%d",&t,&k);
    f[0]=1;
    for (int i=1;i<=100000;i++){
        f[i]=f[i-1];
        if (i>=k) f[i]=(f[i]+f[i-k])%mo;
    }
    for (int i=1;i<=100000;i++) f[i]=(f[i]+f[i-1])%mo;
    for (;t;t--){
        int l,r; scanf("%d%d",&l,&r); printf("%d\n",((f[r]-f[l-1])%mo+mo)%mo);
    }
    return 0;
}