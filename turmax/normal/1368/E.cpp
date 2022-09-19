#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
bool used[maxn];
bool use[maxn];
int tout[maxn];
int ts[maxn];
vector <int> b[maxn];
int r[maxn];
int timer=0;
void dfs(int x)
{
    used[x]=true;
    ++timer;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            dfs(v);
        }
    }
    ++timer;
    tout[x]=timer;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    timer=0;
    for(int i=0;i<n;++i)
    {
        a[i].clear();
        b[i].clear();
        used[i]=false;
        use[i]=true;
        tout[i]=0;
    }
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);b[y].push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
    for(int i=0;i<n;++i)
    {
        r[i]=b[i].size();
    }
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i)
    {
        v.push_back({tout[i],i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector <int> h;
    for(int i=0;i<v.size();++i)
    {
        ts[v[i].second]=i;
        h.push_back(v[i].second);
    }
    vector <int> ans;
    for(int i=0;i<n;++i)
    {
        int x=h[i];
        use[x]=true;
        for(int j=0;j<b[x].size();++j)
        {
            int v=b[x][j];
            if(use[v] && r[v])
            {
                use[x]=false;
                ans.push_back(x);
                break;
            }
        }
        if(!use[x])
        {
            for(int k=0;k<a[x].size();++k)
            {
                int v=a[x][k];
                r[v]--;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]+1<<' ';
    }
    cout<<endl;
    }
    return 0;
}