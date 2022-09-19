#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <pair<int,int> > b[maxn];
vector <int> a[maxn];
vector <pair<int,int> > c[maxn];
set <pair<pair<int,int>,pair<int,int> > > o;
vector <pair<pair<int,int>,pair<int,int> > > z;
int deq[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        deq[x]++;
        b[x].push_back({w,y});
    }
    for(int i=0;i<n;++i)
    {
        sort(b[i].begin(),b[i].end());
        for(int j=0;j<b[i].size();++j)
        {
            a[i].push_back(b[i][j].second);
        }
    }
    /*vector <vector<int> > z[k];
    for(int i=1;i<k;++i)
    {
        for(int j=0;j<=(i-1);++j)
        {
            vector <int> v(n);
            for(int k=0;k<n;++k) v[k]=0;
            for(int k=0;k<n;++k)
            {
                if(deq[k]==i)
                {
                    v[a[k][j]]^=1;
                }
            }
            z[i].push_back(v);
        }
    }*/
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<a[i].size();++j)
        {
            c[a[i][j]].push_back({deq[i]-1,j+1});
            /*cout<<i<<" i "<<endl;
            cout<<deq[i]<<" "<<j+1<<" ban "<<endl;
            cout<<a[i][j]<<" a[i][j] "<<endl;*/
        }
    }
    set <pair<int,int> > g;
    for(int i=0;i<n;++i)
    {
        g.clear();
        vector <pair<int,int> > v1;
        for(int j=0;j<c[i].size();++j)
        {
            if(g.count(c[i][j]))
            {
                pair <pair<int,int>,pair<int,int> > curr={c[i][j],c[i][j]};
                if(!o.count(curr))
                {
                    o.insert(curr);
                    z.push_back(curr);
                }
                continue;
            }
            else
            {
                v1.push_back(c[i][j]);
                g.insert(c[i][j]);
            }
        }
        for(int j=0;j<v1.size();++j)
        {
            for(int k=0;k<j;++k)
            {
                pair <pair<int,int>,pair<int,int> > curr={v1[j],v1[k]};
                if(!o.count(curr))
                {
                    o.insert(curr);
                    z.push_back(curr);
                }
            }
        }
    }
    int u=1;
    for(int i=1;i<=k;++i) u*=i;
    int ans=0;
    for(int i=0;i<u;++i)
    {
        vector <int> v;
        int y=i;
        for(int j=1;j<=k;++j)
        {
            v.push_back(y%j+1);
            y/=j;
        }
        bool h=true;
        for(int j=0;j<z.size();++j)
        {
            if(v[z[j].first.first]==z[j].first.second && v[z[j].second.first]==z[j].second.second)
            {
                h=false;
                break;
            }
        }
        if(h)
        {
            /*for(int i=0;i<k;++i)
        {
            cout<<v[i]<<" v[i] "<<endl;
        }
        cout<<endl;
            cout<<" tgrfed "<<endl;*/
            ans++;
        }
    }
    cout<<ans;
    return 0;
}