#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <pair<int,int> > v[n];
    vector <pair<int,int> > u[m];
    for(int i=0;i<n;++i)
    {
        int c;
        cin>>c;
        for(int j=0;j<c;++j)
        {
            int l,r;
            cin>>l>>r;
            l--;r--;
            v[i].push_back({l,r});
            for(int k=l;k<=r;++k)
            {
                u[k].push_back({l,r});
            }
        }
    }
    int dp[m+2][m+2];
    for(int i=(m+1);i>=0;--i)
    {
        for(int h=0;(i+h)<=(m+1);++h)
        {
            int j=(i+h);
            if((i+1)>=j)
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=0;
            int x=i;
            int y=j;
            x--;y--;
            int z=0;
            for(int l=(x+1);l<y;++l)
            {
                z=0;
                for(int t=0;t<u[l].size();++t)
                {
                    if(u[l][t].first>x && u[l][t].second<y)
                    {
                        z++;
                    }
                }
                //cout<<i<<" "<<j<<" "<<l<<endl;
                dp[i][j]=max(dp[i][j],dp[i][l+1]+dp[l+1][j]+z*z);
            }
        }
    }
    cout<<dp[0][m+1]<<endl;
    return 0;
}