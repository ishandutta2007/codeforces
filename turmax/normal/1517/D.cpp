#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5+5;
vector <vector <pair<int,int> > > a;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    if(k%2==1)
    {
        for(int i=0;i<n;++i) {for(int j=0;j<m;++j)
        {
            cout<<(-1)<<' ';
        }
        cout<<endl;
        }
        return 0;
    }
    a.resize(n*m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(m-1);++j)
        {
            int x;
            cin>>x;
            a[(i*m+j)].push_back({i*m+j+1,x});
            a[(i*m+j+1)].push_back({i*m+j,x});
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        for(int j=0;j<m;++j)
        {
            int x;
            cin>>x;
            a[((i+1)*m+j)].push_back({i*m+j,x});
            a[(i*m+j)].push_back({(i+1)*m+j,x});
        }
    }
    int dp[n*m][k/2+1];
    for(int i=0;i<n*m;++i)
    {
        dp[i][0]=0;
    }
    for(int j=1;j<=k/2;++j)
    {
        for(int i=0;i<n*m;++i)
        {
            dp[i][j]=1e9;
            for(auto h:a[i])
            {
                dp[i][j]=min(dp[i][j],dp[h.first][j-1]+2*h.second);
            }
        }
    }
    for(int i=0;i<n;++i) {for(int j=0;j<m;++j) cout<<dp[i*m+j][k/2]<<' ';cout<<endl;}
    return 0;
}