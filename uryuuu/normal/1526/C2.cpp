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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=300005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn],b[maxn];

void upd(int x,ll val)
{
    while(x<maxn)
    {
        b[x]+=val;
        x+=lb(x);
    }
}

ll qry(int x)
{
    ll sum=0ll;
    while(x)
    {
        sum+=b[x];
        x-=lb(x);
    }
    return sum;
}

struct node
{
    int id;
    ll val;
}s[maxn];

bool cmp(node a,node b)
{
    if(a.val==b.val)
        return a.id<b.id;
    return a.val>b.val;
}

vector<int>g;

int getpos(int pos,ll val)
{
    int l=0,r=pos;
    int mid;
    int mx=-1;
    while(l<r)
    {
        mid=(l+r)/2;
        if(qry(g[mid])<=val)
        {
//            cout<<"OK"<<mid<<' '<<g[mid]<<' '<<qry(g[mid])<<' '<<val<<endl;
            l=mid+1;
            mx=max(mx,mid);
        }
        else
        {
            r=mid;
        }
    }
//    cout<<"L"<<l<<' '<<g[l]<<' '<<qry(g[l])<<' '<<val<<endl;
    if(qry(g[l])<=val)
        mx=max(mx,l);
    return mx;
}

int main()
{
    sync;
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            cnt++;
            s[cnt].id=i;
            s[cnt].val=a[i];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            ans++;
            upd(i,a[i]);
            if(a[i]>0)
                g.push_back(i);
        }
        else
        {
            a[i]=0;
        }
    }
    sort(s+1,s+cnt+1,cmp);
    
    int id;
    ll sum,x,mn,pos;
    int j;
    int L,R;
    for(int i=1;i<=cnt;i++)
    {
        x=s[i].val;
        id=s[i].id;
        x=-x;
        sum=qry(id);
//        cout<<id<<' '<<x<<' '<<sum<<endl;
        if(sum<x)
            continue;
        ans++;
        R=lower_bound(g.begin(),g.end(),id)-g.begin()-1;
        L=getpos(R,sum-x)+1;
//        cout<<L<<' '<<R<<' '<<sum-x<<endl;
        pos=R+1;
        for(j=R;j>=L;j--)
        {
//            cout<<g[j]<<' '<<a[g[j]]<<endl;
            mn=min(a[g[j]],x);
            a[g[j]]-=mn;
            x-=mn;
            upd(g[j],-mn);
            if(a[g[j]]==0)
                pos=j;
        }
        if(pos==R+1)
            continue;
        g.erase(g.begin()+pos,g.begin()+R+1);
    }
    cout<<ans<<endl;

    return 0;
}