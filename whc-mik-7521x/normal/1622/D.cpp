#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,k,a[N];
long long jc[N],jcny[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
long long C(int nn,int mm){
    return (((jc[nn]*jcny[mm])%mod)*jcny[nn-mm])%mod;
}
int main(){
    jc[0]=1;
    for(int i=1;i<N;i++)jc[i]=jc[i-1]*i%mod;
    for(int i=0;i<N;i++)jcny[i]=fp(jc[i],mod-2);
    scanf("%d%d",&n,&k);
    a[0]=a[n+1]=1;
    for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
    int l=0,r=0,cnt=0;
    for(;r<=n+1;r++){
        if(a[r])cnt++;
        if(cnt==(k+2))break;
    }
    if(r==n+2||k==0){
        return puts("1"),0;
    }
    long long ans=0;
    while(r<=n+1){
        int len=r-l-1;
        if(r==n+1){
            ans+=C(len,k);
            break;
        }
        else{
            int i;
            for(i=l+1;!a[i];i++);
            ans+=C(len,k)-C(r-i-1,k-1);
        }
        ans=(ans%mod+mod)%mod;
        for(r=r+1;!a[r];r++);
        for(l=l+1;!a[l];l++);
    }
    printf("%lld",ans%mod);
    return  0;
}