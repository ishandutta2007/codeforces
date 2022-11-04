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
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1000010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


ll n,x,y,z;
ll a[maxn];

ll f(ll h)
{
    ll sum=0;
    ll sy=0,sx=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>h)
        {
            sy+=1ll*a[i]-h;
        }
        else
        {
            sx+=1ll*h-a[i];
        }
    }
    if(x+y>z)
    {
        ll d=min(sx,sy);
        sum=1ll*z*d+(sx-d)*x+(sy-d)*y;
    }
    else
    {
        ll d=0;
        sum=1ll*(sx-d)*x+(sy-d)*y;
    }
    return sum;
}

int main()
{
    sync;
    cin>>n>>x>>y>>z;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    ll l=0,r=1e9+1;
    while(l+1<r)
    {
        int midl=(l+r)/2;
        int midr=(midl+r)/2;
        if(f(midl)>f(midr))
            l=midl;
        else
            r=midr;
    }
    cout<<1ll*f(r)<<endl;
    
    return 0;
}