#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long int ll;
typedef pair <ll,ll> pll;
const ll N=1e5+10,SQ=450,inf=1e5+10;
ll n,m,q,l,r,a[N],f[N],fa[N],b[N],c[N],res[N],vq[10000];
pll p,g[N];
vector <pll> v[N];

void add(ll v,ll c)
{
    for(; v<N; v+=v&-v)
        fa[v]+=c;
}

ll gets(ll ind)
{
    ll ret=0;
    for(; ind; ind-=ind&-ind)
        ret+=fa[ind];
    return ret;
}

void upd(ll s)
{
    ll id=s/SQ;
    vq[id]=inf;
    for(int i=id*SQ; i<(id+1)*SQ && i<n; i++)
        vq[id]=min(vq[id],c[i]);
}

ll get(ll s,ll e)
{
    ll l=s/SQ,r=e/SQ,ret=inf;
    l++;
    for(int i=l; i<r; i++)
        ret=min(ret,vq[i]);
    if(l-r==1)
    {
        for(int i=s; i<=e; i++)
            ret=min(ret,c[i]);
        return ret;
    }
    for(int i=s; i<l*SQ; i++)
        ret=min(ret,c[i]);
    for(int i=r*SQ; i<=e; i++)
        ret=min(ret,c[i]);
    return ret;
}


int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    fill(b,b+N,-1);
    cin >> q;
    for(int i=1; i<=q; i++)
    {
        cin >> l >> r;
        v[r-1].push_back({l-1,i});
    }
    for(int i=0; i<n; i++)
    {
        f[i]=b[a[i]];
        b[a[i]]=i;
        add(i+1,1);
        g[i]=make_pair(-1,0);
        if(f[i]!=-1)
        {
            add(f[i]+1,-1);
            if(g[f[i]].S==0 || g[f[i]].S!=i-f[i]) g[i]=make_pair(f[f[i]],i-f[i]);
            else    if(g[f[i]].S==i-f[i])   g[i]=g[f[i]];
            c[f[i]]=inf;
            upd(f[i]);
        }
        c[i]=g[i].F;
        upd(i);
        r=i;
        for(auto y:v[i])
        {
                l=y.F;
                res[y.S]=gets(r+1)-gets(l);
                if(get(l,r)>=l)
                    res[y.S]++;
        }
    }
    for(int i=1; i<=q; i++)
        cout << res[i] << '\n';
}