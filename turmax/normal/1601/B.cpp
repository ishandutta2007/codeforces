#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=6e5+5;
vector <pair<int,int> > g[maxn];
int is[maxn];
bool used[maxn];
int pr[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) is[i]=1e18;
    int n;
    cin>>n;
    int a[n+1]={0},b[n+1]={0};
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i)
    {
        g[i].push_back({n+1+i-a[i],1});
    }
    for(int i=(n+1);i<=(2*n+1);++i)
    {
        g[i].push_back({i+1,0});
    }
    for(int i=1;i<=n;++i)
    {
        g[n+i+1].push_back({i+b[i],0});
    }
    g[n+1].push_back({0,0});
    set <pair<int,int> > d;
    is[n]=0;
    pr[n]=(-1);
    d.insert({0,n});
    while(!d.empty())
    {
        pair <int,int> o=(*d.begin());
        int x=o.second;
        d.erase(d.begin());
        used[x]=true;
        for(auto v:g[x])
        {
            if(!used[v.first])
            {
                d.erase({is[v.first],v.first});
                int we=is[x]+v.second;
                if(is[v.first]>we)
                {
                    is[v.first]=we;
                    pr[v.first]=x;
                }
                d.insert({is[v.first],v.first});
            }
        }
    }
    if(is[0]==1e18)
    {
        cout<<(-1);
        return 0;
    }
    vector <int> ans;
    int curr=0;
    int curr1=(-1);
    while(true)
    {
        if(curr1<=n && curr>=(n+1)) ans.push_back(curr-n-1);
        if(pr[curr]==(-1)) break;
        curr1=curr;
        curr=pr[curr];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto h:ans) cout<<h<<' ';
    return 0;
}