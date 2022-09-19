#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector <pair<int,int> > a[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int w[n];
    int deq[n];
    for(int i=0;i<n;++i) deq[i]=0;
    for(int i=0;i<n;++i) cin>>w[i];
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back({y,i});a[y].push_back({x,i});
        deq[x]++;deq[y]++;
    }
    set <pair<int,int> > d;
    pair <int,int> is[n];
    for(int i=0;i<n;++i)
    {
        d.insert({-w[i]+deq[i],i});
        is[i]={-w[i]+deq[i],i};
    }
    bool used[n];
    for(int i=0;i<n;++i) used[i]=false;
    vector <int> v;
    while(!d.empty())
    {
        pair <int,int> o=(*d.begin());
        d.erase(d.begin());
        if(o.first>=1)
        {
            cout<<"DEAD";
            return 0;
        }
        int x=o.second;
        used[x]=true;
        for(int i=0;i<a[x].size();++i)
        {
            int y=a[x][i].first;
            if(!used[y])
            {
            v.push_back(a[x][i].second);
            deq[y]--;
            d.erase(is[y]);
            is[y].first--;
            d.insert(is[y]);
            }
        }
    }
    cout<<"ALIVE"<<endl;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<' ';
    }
    return 0;
}