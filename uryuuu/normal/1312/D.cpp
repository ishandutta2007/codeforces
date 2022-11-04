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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double pi=acos(-1);
const int maxn=300005;
//const ll Mod=1000000007;
const ll Mod=998244353;


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

int main()
{
    sync;
    p[0]=inv[0]=1ll;
    for(ll i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
        inv[i]=ksm(p[i],Mod-2)%Mod;
    }
    ll n,m;
    ll ans=0;
    cin>>n>>m;
    for(ll i=n-2;i<=m-1;i++)
    {
//        cout<<ksm(2,n-3)<<' '<<((n-2)*C(i,n-2))<<endl;
        ans=(ans+(ksm(2,n-3)*((n-2)*C(i,n-2)%Mod))%Mod+Mod)%Mod;
    }
    cout<<ans<<endl;
    return 0;
}