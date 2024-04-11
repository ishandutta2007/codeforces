#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1e5+5;
int fact[maxn];int invf[maxn];
int po(int a,int b) {if(b==0) return 1;if(b==1) return a;if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    if(k<0 || k>n) return 0;
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;
}
map<pair<int,int>,int> u;
int n,t;
int f(int bit,int ri)
{
    if(u.count({bit,ri})) return u[{bit,ri}];
    if(ri<0) return 0;
    if(bit==(-1)) return 1;
    int o=(1LL<<bit);
    if(2*o*n<=ri && (o<(1e18/n))) {int h=po((2*o)%p,n-1);h%=p;return h;}
    if(t & o)
    {
        int ans=0;
        for(int k=1;k<=n;k+=2)
        {
            int z=c(n,k);
            if(k>(1e18/o)) break;
            ans+=(z*f(bit-1,ri-k*o));ans%=p;
        }
        u[{bit,ri}]=ans;return ans;
    }
    else
    {
        int ans=0;
        for(int k=0;k<=n;k+=2)
        {
            int z=c(n,k);
            if(k>(1e18/o)) break;
            ans+=(z*f(bit-1,ri-k*o));ans%=p;
        }
        u[{bit,ri}]=ans;return ans;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;invf[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
    int l,r;
    cin>>n>>l>>r>>t;
    int ans=f(60,r);ans-=f(60,l-1);
    cout<<(ans%p+p)%p;
    return 0;
}