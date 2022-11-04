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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

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

ll b[maxn];
map<ll,int>a;
map<ll,int>g[maxn];

int findx(int x,ll key)
{
    if(g[x][key]==x)
        return x;
    return g[x][key]=findx(g[x][key],key);
}

int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    ll ans=ksm(2ll,k)*ksm(2ll,n)%Mod;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int u,v,fu,fv;
    ll key;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        key=(b[u]^b[v]);
        if(g[u][key]==0)
            g[u][key]=u;
        if(g[v][key]==0)
            g[v][key]=v;
        fu=findx(u,key);
        fv=findx(v,key);
        if(fu==fv)
            continue;
        g[fu][key]=fv;
        ans=(ans-ksm(2ll,n-a[key])%Mod)%Mod;
        a[key]++;
        ans=(ans+ksm(2ll,n-a[key])%Mod)%Mod;
    }
    cout<<(ans%Mod+Mod)%Mod;
    
    return 0;
}