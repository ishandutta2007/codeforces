#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,MOD=1e9+7;

map<pii,pii> par;
map<pii,int> sz;
map<pii,bool> tree;

pii dsu(pii x)
{
    if(!par.count(x))
        par[x]=x,
        sz[x]=1,
        tree[x]=true;
    return par[x]==x?x:par[x]=dsu(par[x]);
}

void un(pii x,pii y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return (void)(tree[x]=false);
    if(sz[x]<sz[y])
        swap(x,y);
    par[y]=x;
    sz[x]+=sz[y];
    tree[x]&=tree[y];
}

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        un({x,1},{y,2});
    }
    int ans=1;
    for(auto p:par)
        if(p.x==p.y)
        {
            auto v=p.x;
            int cur=ppow(2,sz[v]);
            if(tree[v])
                cur--;;
            ans=ans*cur%MOD;
        }
    cout<<ans;
}