#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        vector <int> v[n];
        for(int i=0;i<n;++i) {cin>>a[i];a[i]--;v[a[i]].push_back(i);}
        int r[n];
        for(int i=0;i<n;++i)
        {
             v[i].insert(v[i].begin(),-1);
             v[i].push_back(n);
             r[i]=(-1e18);
             for(int j=0;j<v[i].size()-1;++j)
             {
                 r[i]=max(r[i],v[i][j+1]-v[i][j]);
             }
        }
        vector <int> z[n+2];
        for(int i=0;i<=n;++i) z[i].clear();
        for(int i=0;i<n;++i)
        {
            z[r[i]].push_back(i);
        }
        set <int> d;
        for(int i=1;i<=n;++i)
        {
            vector <int> v=z[i];
            for(auto h:v)
            {
                d.insert(h);
            }
            if(d.empty())
            {
                cout<<(-1)<<' ';
            }
            else
            {
                cout<<(*d.begin()+1)<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}