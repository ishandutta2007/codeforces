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
const int maxn=400005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int n,m,k;
struct node
{
    int u,v,id;
    double w;
}e[maxn];

bool cmp(node a,node b)
{
    if(a.w==b.w)
        return a.u<b.u;
    return a.w<b.w;
}
int fa[maxn];
int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}

int ck(double mid)
{
    for(int i=1;i<=m;i++)
    {
        if(e[i].u==1)
            e[i].w+=mid;
    }
    sort(e+1,e+m+1,cmp);
    int res=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int fu,fv;
    for(int i=1;i<=m;i++)
    {
        fu=findx(e[i].u);
        fv=findx(e[i].v);
        if(fu==fv)
            continue;
        fa[fu]=fv;
        if(e[i].u==1)
            res++;
    }
    for(int i=1;i<=m;i++)
    {
        if(e[i].u==1)
            e[i].w-=mid;
    }
    return res;
}

int pt[maxn];

void solve(double mid)
{
    for(int i=1;i<=m;i++)
    {
        if(e[i].u==1)
            e[i].w+=mid;
    }
    sort(e+1,e+m+1,cmp);
    int cnt=0;
    int res=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int fu,fv;
    for(int i=1;i<=m;i++)
    {
        fu=findx(e[i].u);
        fv=findx(e[i].v);
        if(fu==fv||res+(e[i].u==1)>k)
            continue;
        fa[fu]=fv;
        pt[++cnt]=e[i].id;
        if(e[i].u==1)
            res++;
    }
//    cout<<cnt<<' '<<res<<endl;
    if(cnt!=n-1||res!=k)
        cout<<-1<<endl;
    else
    {
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<pt[i]<<' ';
        cout<<endl;
    }
    return ;
}


int main()
{
    sync;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        if(e[i].u>e[i].v)
            swap(e[i].u,e[i].v);
        e[i].id=i;
    }
    double l=-200000,r=200000,mid,ans=-100000000;
    for(int i=1;i<=60;i++)
    {
        mid=(l+r)/2.0;
        if(ck(mid)>=k)
        {
//            cout<<mid<<' '<<ck(mid)<<endl;
            ans=max(mid,ans);
            l=mid;
        }
        else
            r=mid;
    }
    if(ans<-1000000)
        cout<<-1<<endl;
    else
    {
        solve(ans);
    }
    return 0;
}