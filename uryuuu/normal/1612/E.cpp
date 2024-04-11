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
const int maxn=200005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn],b[maxn];
vector<int>g[maxn];
int c[maxn];
int bb[maxn];

struct node
{
    ll id,val;
}s[maxn],ans[maxn];

bool cmp1(int a,int b)
{
    return a>b;
}

bool cmp(node a,node b)
{
    return a.val*b.id>b.val*a.id;
}

bool cmp2(node a,node b)
{
    return a.val>b.val;
}

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        bb[i]=a[i];
    }
    sort(bb+1,bb+n+1);
    int m=unique(bb+1,bb+n+1)-bb-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(bb+1,bb+m+1,a[i])-bb;
        g[a[i]].push_back(b[i]);
    }
    
    int id=0,sum=0;
    int up=max(100,10000000/m);
    up=min(m,up);
    int p,i;
    for(p=1;p<=up;p++)
    {
        sum=0;
        for(i=1;i<=m;i++)
        {
            b[i]=0;
            for(int v:g[i])
            {
                b[i]+=min(p,v);
            }
        }
        sort(b+1,b+m+1,cmp1);
        s[p].id=p;
        s[p].val=0;
        for(i=1;i<=p;i++)
        {
            s[p].val+=1ll*b[i];
        }
    }
    sort(s+1,s+up+1,cmp);
    id=s[1].id;
    p=id;
    for(i=1;i<=m;i++)
    {
        ans[i].id=i;
        ans[i].val=0;
        for(int v:g[i])
        {
            ans[i].val+=min(p,v);
        }
//        cout<<bb[i]<<' '<<ans[i].val<<endl;
    }
    sort(ans+1,ans+m+1,cmp2);
    cout<<p<<endl;
    for(int i=1;i<=p;i++)
    {
        cout<<bb[ans[i].id]<<' ';
    }
    cout<<endl;
    
    return 0;
}