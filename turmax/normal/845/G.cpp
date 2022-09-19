#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
vector <pair<int,int> > a[maxn];
bool used[maxn];
vector <int> g;
vector <int> h;
int pr[maxn];
const int maxw=(1<<27);
bitset <maxw> use;
void dfs(int x)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i].first;
        if(!used[v])
        {
            pr[v]=pr[x]^a[x][i].second;
            dfs(v);
        }
        else
        {
            g.push_back(pr[v]^pr[x]^a[x][i].second);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        a[x].push_back({y,w});a[y].push_back({x,w});
    }
    pr[0]=0;
    dfs(0);
    int ans1=pr[n-1];
    use[0]=true;
    h.push_back(0);
    int curr=0;
    for(int i=0;i<g.size();++i)
    {
        if(!use[g[i]])
        {
            ++curr;
            if(curr==27)
            {
                cout<<0;
                return 0;
            }
            int o=h.size();
            for(int j=0;j<o;++j)
            {
                h.push_back(h[j]^g[i]);
                use[h[j]^g[i]]=1;
            }
        }
    }
    int mi=1e9;
    for(int i=0;i<h.size();++i)
    {
        mi=min(mi,ans1^h[i]);
    }
    cout<<mi;
    return 0;
}