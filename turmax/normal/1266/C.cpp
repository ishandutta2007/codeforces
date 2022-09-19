#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==1 && m==1)
    {
        cout<<0;
        return 0;
    }
    if(n==1)
    {
        for(int i=0;i<m;++i)
        {
            cout<<(i+2)<<" ";
        }
        return 0;
    }
    if(m==1)
    {
        for(int i=0;i<n;++i)
        {
            cout<<(i+2)<<endl;
        }
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<(i+1)*(j+n+1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}