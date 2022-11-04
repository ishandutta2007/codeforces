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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1000005;
//const ll Mod=1000000007;
const ll Mod=998244353;



ll p[maxn],inv[maxn];

ll ksm(ll x,ll y)
{
    ll res=1ll;
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
int main()
{
    sync;
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    
    ll n;
    cin>>n;
    ll ans=0ll,s,t1,t2,d;
    for(int i=0;i<n;i++)
    {
        s=ksm(3ll,i);
        t1=ksm(1ll-s,n);
        t2=ksm(-s,n);
        d=C(n,i)*(t1-t2)%Mod;
        if(i%2)
            ans+=d;
        else
            ans-=d;
        ans=ans%Mod;
    }
    ans=3ll*ans%Mod;
    for(int i=1;i<=n;i++)
    {
        d=1ll*ksm(3ll,i)*ksm(3ll,n*(n-i))%Mod;
        d=C(n,i)*d%Mod;
        if(i%2)
            ans+=2ll*d;
        else
            ans-=2ll*d;
        ans=ans%Mod;
    }
    cout<<(ans%Mod+Mod)%Mod<<endl;
    return 0;
}