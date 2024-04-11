#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=1010;

int par[N];
int sz[N];
multiset<int,greater<int>> comp;

int dsu(int x)
{
    return par[x]==x?x:par[x]=dsu(par[x]);
}

bool un(int x,int y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return false;
    comp.erase(comp.find(sz[x]));
    comp.erase(comp.find(sz[y]));
    if(sz[x]<sz[y])
        par[x]=y;
    else
        par[y]=x;
    comp.insert(sz[x]=sz[y]=sz[x]+sz[y]);
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        par[i]=i,
        comp.insert(1),
        sz[i]=1;
    int cnt=1;
    while(d--)
    {
        int x,y;
        cin>>x>>y;
        cnt+=!un(x,y);
        int ans=0;
        for(auto[i,it]=pair(0,comp.begin());i<cnt;i++,it++)
            ans+=*it;
        cout<<ans-1<<"\n";
    }
}