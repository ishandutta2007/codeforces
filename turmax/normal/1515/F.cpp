#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector <pair<int,int> > b;
int l1;
set <int> good;
vector <int> a[maxn];
vector <pair<int,int> > z[maxn];
int l[maxn];
map <pair<int,int>,int> h;
int parent[maxn];
int c[maxn];
int get(int x)
{
    if(parent[x]==(-1)) return x;
    int ans=get(parent[x]);
    parent[x]=ans;
    return ans;
}
int x;
void merg(int u,int v)
{
    if(z[u].size()>z[v].size()) swap(u,v);
    parent[u]=v;
    c[v]=(c[u]+c[v]-x);
    if(c[v]>=x) good.insert(v);
    for(int i=l[u];i<z[u].size();++i)
    {
        z[v].push_back(z[u][i]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    l1=0;
    for(int i=0;i<maxn;++i) {l[i]=0;parent[i]=(-1);}
    int n,m;
    cin>>n>>m>>x;
    int sum=0;
    for(int i=0;i<n;++i) {cin>>c[i];sum+=c[i];if(c[i]>=x) good.insert(i);}
    if(sum>=((n-1)*x))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        b.push_back({u,v});
        h[{u,v}]=i;h[{v,u}]=i;
        a[u].push_back(v);a[v].push_back(u);
        z[u].push_back({v,i});z[v].push_back({u,i});
    }
    while(true)
    {
        if(!good.empty())
        {
            int u=(*good.begin());
            if(get(u)!=u || c[u]<x)
            {
                good.erase(good.begin());
                continue;
            }
            bool ok=false;
            for(int i=l[u];i<z[u].size();++i)
            {
                z[u][i].first=get(z[u][i].first);
                if(z[u][i].first==u) {l[u]++;continue;}
                cout<<z[u][i].second+1<<endl;
                ok=true;
                merg(u,z[u][i].first);
                break;
            }
            if(!ok)
            {
                good.erase(good.begin());
                continue;
            }
        }
        else if(l1!=b.size())
        {
            for(int i=l1;i<b.size();++i)
            {
                int u=get(b[i].first);int v=get(b[i].second);
                if(u==v)
                {
                    ++l1;
                    continue;
                }
                else
                {
                    cout<<(i+1)<<endl;
                    merg(u,v);
                    continue;
                }
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}