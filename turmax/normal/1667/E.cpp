#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=2e5+5;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int fact[maxn];int invf[maxn];
int c(int n,int k) {if(k<0 || n<k || n<0) return 0; int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<maxn;++i) fact[i]=(fact[i-1]*i)%p; for(int i=0;i<maxn;++i) invf[i]=inv(fact[i]);
    int n;cin>>n;int ans[n+1]={0};int sum=0;
    ans[1]=fact[n-1];
    for(int i=2;i<=n;++i)
    {
        int h=fact[n-i]*fact[i-1];h%=p;
        ans[i]=c((n-1)/2,(n+1)/2-i);
        ans[i]*=h;ans[i]%=p;
    }
    for(int i=n;i>=1;--i)
    {
        int sum1=sum;
        sum+=(ans[i]*inv(i-1));sum%=p;
        ans[i]-=sum1;ans[i]%=p;ans[i]+=p;ans[i]%=p;
    }
    for(int i=1;i<=n;++i) cout<<(ans[i]%p+p)%p<<' ';
    return 0;
}