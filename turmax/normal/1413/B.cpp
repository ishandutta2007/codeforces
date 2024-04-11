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
        int n,m;
        cin>>n>>m;
        vector <int> a[n];
        vector <int> b[m];
        int is[n*m];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int x;
                cin>>x;
                x--;
                is[x]=i;
                a[i].push_back(x);
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int x;
                cin>>x;
                x--;
                b[i].push_back(x);
            }
        }
        vector <vector <int> > v;
        for(auto h:b[0])
        {
            v.push_back(a[is[h]]);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cout<<v[i][j]+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}