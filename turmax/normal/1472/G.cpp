#include <bits/stdc++.h>

using namespace std;
#define int long long
deque <int> q;
deque <int> q1;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector <vector <int> > a;a.clear();a.resize(n);
        vector <pair<int,int> > b;
        for(int i=0;i<m;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);
            b.push_back({x,y});
        }
        int is[n];
        is[0]=0;
        for(int i=1;i<n;++i) is[i]=1e18;
        q.clear();
        q.push_back(0);
        while(!q.empty())
        {
            q1.clear();
            while(!q.empty())
            {
                int x=q.back();
                q.pop_back();
                for(auto v:a[x])
                {
                    if(is[v]==1e18)
                    {
                        is[v]=is[x]+1;
                        q1.push_back(v);
                    }
                }
            }
            q=q1;
        }
        //for(int i=0;i<n;++i) cout<<is[i]<<' ';
        //cout<<'\n';
        vector <vector <int> > a1(n);
        int l[n];
        int res[n];
        for(int i=0;i<n;++i) l[i]=is[i];
        for(int i=0;i<b.size();++i)
        {
            int x=b[i].first;int y=b[i].second;
            if(is[x]<is[y])
            {
                a1[x].push_back(y);
            }
            else
            {
                l[x]=min(l[x],is[y]);
            }
        }
        for(int i=0;i<n;++i) res[i]=l[i];
        vector <pair<int,int> > v;
        for(int i=0;i<n;++i) v.push_back({is[i],i});
        sort(v.begin(),v.end());reverse(v.begin(),v.end());
        for(int i=0;i<n;++i)
        {
            int x=v[i].second;
            for(auto v:a1[x])
            {
                res[x]=min(res[x],res[v]);
            }
        }
        for(int i=0;i<n;++i) cout<<res[i]<<' ';
        cout<<'\n';
    }
    return 0;
}