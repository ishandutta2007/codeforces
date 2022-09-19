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
        string a[n];
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            a[i]=s;
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(a[i][m-1]=='R')
            {
                ++ans;
            }
        }
        for(int i=0;i<m;++i)
        {
            if(a[n-1][i]=='D')
            {
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}