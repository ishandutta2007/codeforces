#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector <int> v)
{
    int u0=0;
    int u1=0;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==0)
        {
            u0++;
        }
        else
        {
            u1++;
        }
    }
    return min(u0,u1);
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
            if(2*(i+j)==(n+m-2))
            {
                a[i][j]=0;
            }
        }
    }
    int ans=0;
    vector <int> v;
    for(int l=0;l<=(n+m-2)/2;++l)
    {
        v.clear();
        for(int i=0;i<min(n,l+1);++i)
        {
            int j=(l-i);
            if(j<m && j>=0)
            {
                v.push_back(a[i][j]);
            }
        }
        int l2=(n+m-2-l);
        for(int i=0;i<min(n,l2+1);++i)
        {
            int j=(l2-i);
            if(j<m && j>=0)
            {
                v.push_back(a[i][j]);
            }
        }
        ans+=go(v);
        //cout<<v.size()<<" size "<<endl;
    }
    cout<<ans<<endl;
    }
    return 0;
}