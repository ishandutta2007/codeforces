#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100;

int up[N],down[N],tp[N];
vector<pii> g[N];

pii far(int v,int p)
{
    pii res(-1,v);
    for(pii to:g[v])
        if(to.x!=p)
            res=max(res,far(to.x,v));
    res.x++;
    return res;
}

int dist1[N],dist2[N];

void calc_dist(int v,int p,int*arr,int d)
{
    arr[v]=d;
    for(pii to:g[v])
        if(to.x!=p)
            calc_dist(to.x,v,arr,d+1);
}

vector<int> euler;
int l[N],r[N];
int tim=0;

void build_euler(int v,int p)
{
    euler.push_back(v);
    l[v]=euler.size()-1;
    for(pii to:g[v])
        if(to.x!=p)
        {
            if(up[to.y]!=v)
                swap(up[to.y],down[to.y]);
            build_euler(to.x,v);
        }
    r[v]=euler.size()-1;
}

struct el
{
    int odd1,odd2,even1,even2;
};

void inv(el&e)
{
    swap(e.odd1,e.even1);
    swap(e.odd2,e.even2);
}

el add(el x,el y)
{
    return el{max(x.odd1,y.odd1),
              max(x.odd2,y.odd2),
              max(x.even1,y.even1),
              max(x.even2,y.even2)};
}

el t[4*N];
bool p[4*N];

void build(int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=el{0,0,dist1[euler[tl]],
                    dist2[euler[tl]]};
    else
    {
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=add(t[v*2],t[v*2+1]);
    }
}

void push(int v,int tl,int tr)
{
    if(!p[v])
        return;
    if(tl!=tr)
    {
        p[v*2]=!p[v*2];
        p[v*2+1]=!p[v*2+1];
    }
    p[v]=false;
    inv(t[v]);
}

void upd(int v,int tl,int tr,int l,int r)
{
    if(l<=tl&&tr<=r)
    {
        p[v]=!p[v];
        push(v,tl,tr);
        return;
    }
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    if(r<=tm)
        upd(v*2,tl,tm,l,r),
        push(v*2+1,tm+1,tr);
    else if(l>=tm+1)
        push(v*2,tl,tm),
        upd(v*2+1,tm+1,tr,l,r);
    else
        upd(v*2,tl,tm,l,r),
        upd(v*2+1,tm+1,tr,l,r);
    t[v]=add(t[v*2],t[v*2+1]);
}

el get(int v,int tl,int tr,int l,int r)
{
    push(v,tl,tr);
    if(l<=tl&&tr<=r)
        return t[v];
    int tm=(tl+tr)/2;
    if(r<=tm)
        return get(v*2,tl,tm,l,r);
    else if(l>=tm+1)
        return get(v*2+1,tm+1,tr,l,r);
    else
        return add(get(v*2,tl,tm,l,r),
                   get(v*2+1,tm+1,tr,l,r));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>up[i]>>down[i]>>tp[i];
        g[up[i]].push_back({down[i],i});
        g[down[i]].push_back({up[i],i});
    }
    int a=far(1,-1).y;
    int b=far(a,-1).y;
    calc_dist(a,-1,dist1,0);
    calc_dist(b,-1,dist2,0);
    build_euler(a,-1);
    build(1,0,n-1);
    for(int i=1;i<=n-1;i++)
        if(tp[i])
            upd(1,0,n-1,l[down[i]],r[down[i]]);
    int m;
    cin>>m;
    while(m--)
    {
        int i;
        cin>>i;
        upd(1,0,n-1,l[down[i]],r[down[i]]);
        auto res=get(1,0,n-1,0,n-1);
        cout<<max(res.even1,res.odd2)<<"\n";
    }
}