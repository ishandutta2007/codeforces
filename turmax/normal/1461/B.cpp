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
        char a[n][m];
        for(int i=0;i<n;++i) {string s;cin>>s;for(int j=0;j<m;++j) a[i][j]=s[j];}
        int d[n][m];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j]=='*')
                {
                    d[i][j]=1;
                }
                else
                {
                    d[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=(n-1);i>=0;i--)
        {
            for(int j=(m-1);j>=0;j--)
            {
                if(i==(n-1) || j==(m-1) || j==0) {ans+=d[i][j];continue;}
                if(!d[i][j]) {ans+=d[i][j];continue;}
                d[i][j]=max(d[i][j],min({d[i+1][j-1],d[i+1][j],d[i+1][j+1]})+1);
                ans+=d[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}