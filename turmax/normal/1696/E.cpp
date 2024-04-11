#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;const int maxn=4e5+5;
int fact[maxn];int invf[maxn];
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;invf[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
    int n;cin>>n;++n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=(c(i+a[i],i+1));
        ans%=p;
    }
    cout<<(ans%p+p)%p;
    return 0;
}