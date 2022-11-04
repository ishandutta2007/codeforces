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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll a[maxn],b[maxn],c[maxn];

ll prea[maxn],preb[maxn];
ll pre[maxn];

ll mx[maxn<<2],mn[maxn<<2];

void pushup(int rt)
{
    mx[rt]=max(mx[lr],mx[rr]);
    mn[rt]=min(mn[lr],mn[rr]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        mx[rt]=mn[rt]=pre[l];
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
    return;
}

ll qrymx(int rt,int l,int r,int L,int R)
{
    if(L>R)
        return -1e18;
    if(l>=L&&r<=R)
        return mx[rt];
    int mid=(l+r)/2;
    if(mid<L)
        return qrymx(rr,mid+1,r,L,R);
    else if(mid+1>R)
        return qrymx(lr,l,mid,L,R);
    return max(qrymx(rr,mid+1,r,L,R),qrymx(lr,l,mid,L,R));
}

ll qrymn(int rt,int l,int r,int L,int R)
{
    if(L>R)
        return 1e18;
    if(l>=L&&r<=R)
        return mn[rt];
    int mid=(l+r)/2;
    if(mid<L)
        return qrymn(rr,mid+1,r,L,R);
    else if(mid+1>R)
        return qrymn(lr,l,mid,L,R);
    return min(qrymn(rr,mid+1,r,L,R),qrymn(lr,l,mid,L,R));
}



int main()
{
    sync;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        prea[i]=prea[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        preb[i]=preb[i-1]+b[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        c[i]=b[i]-a[i];
        pre[i]=pre[i-1]+c[i];
    }
    
    build(1,1,n);

    
    int l,r;
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        if(prea[r]-prea[l-1]!=preb[r]-preb[l-1])
        {
            cout<<-1<<endl;
            continue;
        }
        if(qrymn(1,1,n,l,r)<pre[l-1])
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<qrymx(1,1,n,l,r)-pre[l-1]<<endl;
    }
    
    
    
    return 0;
}