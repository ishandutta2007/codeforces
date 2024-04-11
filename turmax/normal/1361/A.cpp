#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
vector <int> a[maxn];
int mex(vector <int> v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();++i)
    {
        if(v[i]!=(i+1))
        {
            return (i+1);
        }
    }
    return v.size()+1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    int b[n];
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        //cout<<i<<" i "<<endl;
        int x=i;
        vector <int> v;
        for(int j=0;j<a[i].size();++j)
        {
            int y=a[i][j];
            if(b[x]==b[y])
            {
                cout<<(-1);
                return 0;
            }
            //cout<<b[y]<<" b[y] "<<endl;
            v.push_back(b[y]);
        }
        if(mex(v)!=b[x])
        {
            cout<<(-1);
            return 0;
        }
    }
    vector <pair<int,int> > g;
    for(int i=0;i<n;++i)
    {
        g.push_back({b[i],i});
    }
    sort(g.begin(),g.end());
    for(int i=0;i<n;++i)
    {
        cout<<g[i].second+1<<" ";
    }
    return 0;
}