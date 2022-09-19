#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector <int> v)
{
    //cout<<v.size()<<" size "<<endl;
    int ans=1e18;
    for(int i=0;i<v.size();++i)
    {
        //cout<<v[i]<<" v[i] "<<endl;
        int curr=0;
        for(int j=0;j<v.size();++j)
        {
            curr+=abs(v[i]-v[j]);
        }
        ans=min(ans,curr);
    }
    //cout<<ans<<" ans "<<endl;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>a[i][j];
            }
        }
        vector <int> v;
        int ans=0;
        for(int i=0;i<(n/2);++i)
        {
            for(int j=0;j<(m/2);++j)
            {
                v.clear();
                v.push_back(a[i][j]);v.push_back(a[n-i-1][j]);v.push_back(a[i][m-1-j]);v.push_back(a[n-i-1][m-1-j]);
                ans+=go(v);
            }
        }
        if(n%2==1)
        {
            int i=(n/2);
            for(int j=0;j<(m/2);++j)
            {
                v.clear();
                v.push_back(a[i][j]);v.push_back(a[i][m-1-j]);
                ans+=go(v);
            }
        }
        if(m%2==1)
        {
            int j=(m/2);
            for(int i=0;i<(n/2);++i)
            {
                v.clear();
                v.push_back(a[i][j]);v.push_back(a[n-1-i][j]);
                ans+=go(v);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}