#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
bool used[maxn];
int timer;
int timeout[maxn];
void dfs(int x)
{
    used[x]=true;
    ++timer;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
        }
    }
    ++timer;
    timeout[x]=timer;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    timer=0;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i) {a[i].clear();used[i]=false;}
    vector <pair<int,int> > b;
    for(int i=0;i<m;++i)
    {
        int t,x,y;
        cin>>t>>x>>y;
        x--;y--;
        b.push_back({x,y});
        if(t==1)
        {
            a[x].push_back(y);
        }
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i)
    {
        v.push_back({timeout[i],i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ts[n];
    for(int i=0;i<n;++i)
    {
        ts[v[i].second]=i;
    }
    bool h=true;
    for(int i=0;i<n;++i)
    {
        if(!h)
        {
            break;
        }
        for(auto v:a[i])
        {
            if(ts[v]<=ts[i])
            {
                cout<<"NO"<<endl;
                h=false;
                break;
            }
        }
    }
    if(!h)
    {
        continue;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<b.size();++i)
    {
        if(ts[b[i].first]>=ts[b[i].second])
        {
            swap(b[i].first,b[i].second);
        }
        cout<<b[i].first+1<<' '<<b[i].second+1<<endl;
    }
    }
    return 0;
}