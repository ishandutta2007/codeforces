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
        char a[n][n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>a[i][j];
            }
        }
        vector <pair<int,int> > v;
        if(a[0][1]=='0' && a[1][0]=='0')
        {
            if(a[n-1][n-2]=='0' && a[n-2][n-1]=='0')
            {
                v.push_back({n-2,n-1});
                v.push_back({n-1,n-2});
            }
            else if(a[n-1][n-2]=='1' && a[n-2][n-1]=='0')
            {
                v.push_back({n-2,n-1});
            }
            else if(a[n-1][n-2]=='0' && a[n-2][n-1]=='1')
            {
                v.push_back({n-1,n-2});
            }
            else
            {
            }
        }
        else if(a[0][1]=='1' && a[1][0]=='0')
        {
            if(a[n-1][n-2]=='0' && a[n-2][n-1]=='0')
            {
                v.push_back({1,0});
            }
            else if(a[n-1][n-2]=='1' && a[n-2][n-1]=='0')
            {
                v.push_back({n-2,n-1});
                v.push_back({0,1});
            }
            else if(a[n-1][n-2]=='0' && a[n-2][n-1]=='1')
            {
                v.push_back({n-1,n-2});
                v.push_back({0,1});
            }
            else
            {
                v.push_back({0,1});
            }
        }
        else if(a[0][1]=='0' && a[1][0]=='1')
        {
            if(a[n-1][n-2]=='0' && a[n-2][n-1]=='0')
            {
                v.push_back({0,1});
            }
            else if(a[n-1][n-2]=='1' && a[n-2][n-1]=='0')
            {
                v.push_back({n-2,n-1});
                v.push_back({1,0});
            }
            else if(a[n-1][n-2]=='0' && a[n-2][n-1]=='1')
            {
                v.push_back({n-1,n-2});
                v.push_back({1,0});
            }
            else
            {
                v.push_back({1,0});
            }
        }
        else
        {
            if(a[n-1][n-2]=='1' && a[n-2][n-1]=='1')
            {
                v.push_back({n-2,n-1});
                v.push_back({n-1,n-2});
            }
            else if(a[n-1][n-2]=='0' && a[n-2][n-1]=='1')
            {
                v.push_back({n-2,n-1});
            }
            else if(a[n-1][n-2]=='1' && a[n-2][n-1]=='0')
            {
                v.push_back({n-1,n-2});
            }
            else
            {
            }
        }
        cout<<v.size()<<endl;
        for(auto h:v) cout<<h.first+1<<' '<<h.second+1<<endl;
    }
    return 0;
}