#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
const int maxn=1e5+5;
int fact[maxn];int invf[maxn];
int c(int n,int k) {int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;}
int32_t main()
{
    int n,k;cin>>n>>k;
    fact[0]=1;for(int i=1;i<=n;++i) {fact[i]=(fact[i-1]*i)%p;} for(int i=0;i<=n;++i) invf[i]=inv(fact[i]);
    int ans=0;
    for(int i=0;i<=k && i<=n;++i) {ans+=c(n,i);if(ans>=p) ans-=p;}
    cout<<ans;
    return 0;
}