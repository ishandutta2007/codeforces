#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int b[k];
    for(int i=0;i<k;++i)
    {
        cin>>b[i];
    }
    set <pair<int,int> > g;
    vector <vector <int> > u;
    for(int i=(n-1);i>=0;i--)
    {
        int c=b[a[i]-1];
        if(g.empty() || (*g.begin()).first>=c)
        {
            g.insert({1,u.size()});
            vector <int> v;
            v.push_back(a[i]);
            u.push_back(v);
        }
        else
        {
            pair <int,int> z=(*g.begin());
            int y=z.second;
            u[y].push_back(a[i]);
            g.erase(z);
            z.first++;
            g.insert(z);
        }
    }
    cout<<u.size()<<endl;
    for(int i=0;i<u.size();++i)
    {
        cout<<u[i].size()<<" ";
        for(int j=0;j<u[i].size();++j)
        {
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}