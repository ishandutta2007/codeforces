#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;
//const ll Mod=998244353;
   

ll a[maxn];

ll p[maxn],inv[maxn];

ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

map<ll,int>mp;

int main()
{
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    sync;
   
    ll n;
    cin>>n;
    ll sum=0ll;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mp[a[i]]++;
    }
    
    if(sum%n)
    {
        cout<<0<<endl;
        return 0;
    }
    
    sum/=n;
    int L=0,mid=0,R=0;
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]<sum)
            L++;
        else if(a[i]==sum)
            mid++;
        else
            R++;
    }
    
    ll ans;
    
    if(L==1||R==1||mid==n)
    {
        ans=p[n];
        for(auto f:mp)
        {
            ans=1ll*ans*inv[f.second]%Mod;
        }
        cout<<(ans%Mod+Mod)%Mod<<endl;
        return 0;
    }
    
    ll summid=C(n,mid)*p[mid]%Mod;
    
    ans=2ll*p[L]*p[R]%Mod;
    ans=ans*summid%Mod;
    
    for(auto f:mp)
    {
        ans=1ll*ans*inv[f.second]%Mod;
    }
    cout<<(ans%Mod+Mod)%Mod<<endl;

    return 0;
}