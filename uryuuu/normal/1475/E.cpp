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

ll a[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

map<ll,int>vis,mp;


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
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        mp.clear();
        vis.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=m;i++)
        {
            vis[a[i]]++;
        }
        ll ans=C(mp[a[m]],vis[a[m]]);
        ans=(ans%Mod+Mod)%Mod;
        cout<<ans<<endl;
    }
    
    return 0;
}