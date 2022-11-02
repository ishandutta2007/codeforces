#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 2e5+9; 
ll qpow(ll x,ll y){ll t=1;while(y){if(y&1) (t*=x)%=mod;(x*=x)%=mod,y>>=1;}return t;}
int n,q;
ll a[N],s1[N],s2[N],s3[N];
ll l1[N],l2[N],l3[N];

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        s1[i]=(s1[i-1]+a[i])%mod;
        s2[i]=(s2[i-1]+a[i]*a[i])%mod;
        s3[i]=(s3[i-1]+a[i]*a[i]%mod*a[i])%mod;
    }
    for(int i=1;i<=n;i++) l1[i]=(l1[i-1]+i)%mod,l2[i]=(l2[i-1]+1ll*i*i%mod)%mod,l3[i]=(l3[i-1]+1ll*i*i%mod*i%mod)%mod;
    while(q--){
        int l,r,len;ll d;scanf("%d%d%lld",&l,&r,&d);
        len=r-l+1;if(len==1){printf("Yes\n");continue;}
        ll x=(s1[r]+mod-s1[l-1]+mod-1ll*len*(len-1)/2%mod*d%mod)%mod;
        (x*=qpow(len,mod-2))%=mod;
        ll ss=x*x%mod*len%mod+l2[len-1]*d%mod*d%mod+d*x*2%mod*l1[len-1]%mod;
        ss%=mod;
        if(ss==(s2[r]+mod-s2[l-1])%mod){
            ss=x*x%mod*x%mod*len%mod+d*x%mod*x*3%mod*l1[len-1]%mod+d*d%mod*x%mod*3*l2[len-1]%mod+d*d%mod*d%mod*l3[len-1]%mod;
            ss%=mod;
            if(ss=(s3[r]+mod-s3[l-1])%mod){
                printf("Yes\n");
            }
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}
/*
(x+id)^2=x^2+i^2d^2+2idx
lenx^2+(1^2+2^2+..+(len-1)^2)d^2+2dx(1+2+..+len-1)
(x+id)^3=x^3+(3dx^2)i+(3d^2x)i^2+i^3d^3
*/