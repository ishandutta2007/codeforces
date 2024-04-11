#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

int x[N],y[N],c[N],k[N],p[N];

int dsu(int v)
{
    return p[v]==v?v:p[v]=dsu(p[v]);
}

bool un(int u,int v)
{
    u=dsu(u);
    v=dsu(v);
    if(u==v)
        return false;
    if(rand()%2)
        p[u]=v;
    else
        p[v]=u;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        cin>>k[i];
    vector<pair<int,pair<int,int>>> edges;
    for(int i=1;i<=n;i++)
        edges.push_back({c[i],{0,i}});
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            edges.push_back({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),{i,j}});
    sort(edges.begin(),edges.end());
    for(int i=0;i<=n;i++)
        p[i]=i;
    int ans=0;
    vector<int> one;
    vector<pair<int,int>> pr;
    for(auto e:edges)
    {
        int len=e.first;
        int u=e.second.first;
        int v=e.second.second;
        if(un(u,v))
        {
            ans+=len;
            if(u==0)
                one.push_back(v);
            else
                pr.push_back({u,v});
        }
    }
    cout<<ans<<"\n";
    cout<<one.size()<<"\n";
    for(int v:one)
        cout<<v<<" ";
    cout<<"\n";
    cout<<pr.size()<<"\n";
    for(auto p:pr)
        cout<<p.first<<" "<<p.second<<"\n";
}