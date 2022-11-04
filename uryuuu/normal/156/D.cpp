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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
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
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int fa[maxn];
int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}
ll s[maxn];
ll Mod;

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

int main()
{
    sync;
    int n,m;
    cin>>n>>m>>Mod;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        fa[findx(u)]=findx(v);
    }
    for(int i=1;i<=n;i++)
    {
        s[findx(i)]++;
    }
    ll pre=1ll;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(findx(i)==i)
        {
            k++;
            pre=1ll*pre*s[i]%Mod;
        }
    }
    if(k==1)
    {
        cout<<1%Mod<<endl;
        return 0;
    }
    cout<<(pre*ksm(1ll*n,k-2)%Mod+Mod)%Mod<<endl;
    return 0;
}