#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
typedef long double lb;
const ll mod=998244353;
ll jc[N],jcny[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
ll com(ll x,ll y){
    return (((jc[x]*jcny[y])%mod)*jcny[x-y])%mod;
}
ll n,cnt1,cnt2,cnt3,cnt4,msk1,msk2;
int main(){
    jc[0]=1;
    for(int i=1;i<N;i++){
        jc[i]=(jc[i-1]*i)%mod;
    }
    for(int i=0;i<N;i++){
        jcny[i]=fp(jc[i],mod-2);
    }
    scanf("%lld\n",&n);
    ll res=1,wb=1,bw=1;
    for(int i=1;i<=n;i++){
        char s,ss;
        if((s=getchar())=='W')cnt1++,msk1|=1;
        if(s=='B')cnt2++,msk1|=2;
        if((ss=getchar())=='W')cnt4++,msk2|=1;
        if(ss=='B')cnt3++,msk2|=2;
        if(s!='?'&&s==ss)res=0;
        if(s=='?'&&ss==s)res*=2;
        res%=mod;
        if(s=='W'||ss=='B')wb=0;
        if(s=='B'||ss=='W')bw=0;
        getchar();
    }
    ll ans=wb+bw;
    if(cnt1+cnt4>n||cnt2+cnt3>n)return printf("0\n"),0;
    ans+=com(n*2-cnt1-cnt4-cnt2-cnt3,n-cnt1-cnt4);
    ans%=mod;
    // for(int i=max(cnt1,cnt3);i<=n-max(cnt2,cnt4);i++){
    //     ans+=(com(n-cnt1-cnt2,i-cnt1)*com(n-cnt3-cnt4,i-cnt3))%mod;
    //     ans%=mod;
    // }
    printf("%lld",(ans-res+mod)%mod);
    return  0;
}