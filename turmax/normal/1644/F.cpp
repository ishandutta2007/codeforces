#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=4e5+5;
int fact[maxn];int invf[maxn];int num[maxn];int lp[maxn];int pon[maxn];int h[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) {int u=po(a,b/2);return (u*u)%p;}
    else {int u=po(a,b-1);return (a*u)%p;}
}
int inv(int x) {return po(x,p-2);}
int g(int n,int k)
{
    if(k==1) return 1;
    if(k>n) return 0;
    return (k*g(n-1,k)+g(n-1,k-1))%p;
}
int f(int n,int k)
{
    int ans=0;
    for(int i=0;i<=k;++i)
    {
        if(lp[i]==(-1)) {h[i]=po(i,n);}
        else h[i]=(h[lp[i]]*h[i/lp[i]])%p;
        int val=((num[k-i]*invf[i])%p)*h[i];if((k-i) & 1) val*=(-1);ans+=val;ans%=p;
    }
    ans%=p;
    return (ans%p+p)%p;
    //if(n==1) return 1;
    //if(k==1) return 1;
    //if(k==2) return (1<<(n-1));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<maxn;++i) fact[i]=(fact[i-1]*i)%p;
    num[0]=1;num[1]=0;
    for(int i=0;i<maxn;++i) invf[i]=inv(fact[i]);
    for(int i=2;i<maxn;++i) {num[i]=invf[i]-num[i-1];if(num[i]<0) num[i]+=p;}
    int n,k;
    cin>>n>>k;
    if(k==1) {cout<<1;return 0;}
    if(n==1) {cout<<1;return 0;}
    int z[maxn+1];bool used[maxn+1]={0};used[1]=true;
    lp[0]=(-1);lp[1]=(-1);
    z[1]=1;for(int i=2;i<=maxn;++i) {if(!used[i]) {z[i]=(-1);lp[i]=(-1);for(int j=2;i*j<=maxn;++j) {lp[i*j]=i;z[i*j]=z[i]*z[j];used[i*j]=true;if(j%i==0) z[i*j]=0;}}}
    int ans=0;int lst;
    for(int i=1;i<=n;++i)
    {
        int ans1;
        if(i!=1 && (n+i-1)/i==(n+i-2)/(i-1)) {ans1=lst;}
        else {ans1=f((n+i-1)/i,k)-1;lst=ans1;}
        ans+=z[i]*ans1;ans%=p;
    }
    cout<<(ans%p+p)%p;
    return 0;
}