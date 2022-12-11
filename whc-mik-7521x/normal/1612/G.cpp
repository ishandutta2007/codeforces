#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
typedef long double lb;
const ll mod=1e9+7;
ll jc[N],jcny[N],pd[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
ll n,a[N],tot;
bool cmp(ll ko,ll kp){return ko>kp;}
ll dc(ll sx,ll gc,ll xs){
    return (2*sx-gc*(xs-1))*xs/2;
}
int main(){
    jc[0]=1;
    for(ll i=1;i<N;i++)jc[i]=jc[i-1]*i%mod;
    scanf("%lld",&n);
    ll apl=0;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        tot+=a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)if(a[i]&1)pd[i]=1,a[i]--,apl++;
    ll ans1=0,ans2=jc[apl],cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(pd[i])cnt1++;
        else cnt2++;
        ans2=(ans2*fp(((jc[cnt1]*jc[cnt1])%mod)*((jc[cnt2]*jc[cnt2])%mod)%mod,(a[i]-a[i+1])/2))%mod;
        for(ll o=a[i];o>a[i+1];o-=2){
            ans1+=((((tot-cnt1)*cnt1)%mod)*o)%mod;
            ans1%=mod;
            tot-=cnt1*2;
            ans1+=((((tot-cnt2)*cnt2)%mod)*(o-1))%mod;
            ans1%=mod;
            tot-=cnt2*2;
        }
    }
    printf("%lld %lld",ans1,ans2);
    return  0;
}