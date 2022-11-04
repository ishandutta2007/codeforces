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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1000010;
const ll Mod=1000000007;
//const ll Mod=998244353;

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
    if(m<0||n<0||n<m)
        return 0;
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}


ll pre[maxn];


int main()
{
    sync;
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=1ll*p[i-1]*i%Mod;
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll sum=0;

    for(int i=1;i<n;i++)
    {
        if(i>m)
            break;
        ll s=C(m-1,i-1)*C(n-2,i-1)%Mod;
        s=1ll*s*p[i-1]%Mod;
        s=1ll*s*ksm(m,n-i-1)%Mod;
        if(i<n-1)
        {
            s=1ll*s*ksm(n,n-i-2)%Mod;
            s=1ll*s*(i+1)%Mod;
        }
        sum=(1ll*s+sum+Mod+Mod)%Mod;
    }
    
    sum=(1ll*sum+Mod)%Mod;
    
    cout<<sum<<endl;
    return 0;
}