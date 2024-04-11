#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv1(vector <vector <pair<int,int> > > v)
{
    int n=v.size();
    return min({v[0][0].first,v[0][0].second,v[0][n-1].first,v[0][n-1].second,v[n-1][n-1].first,v[n-1][n-1].second,v[n-1][0].first,v[n-1][0].second});
    /*int n=v.size();
    cout<<n<<" n "<<endl;
    int dp[n][n+1];
    for(int i=0;i<n;++i) for(int j=0;j<=n;++j) dp[i][j]=0;
    for(int i=0;i<n;++i)
    {
        int sum=0;
        for(int j=0;j<n;++j) sum+=v[i][j].second;
        for(int j=0;j<=n;++j)
        {
            if(j!=0) sum+=(v[i][j-1].first-v[i][j-1].second);
            if(i==0)
            {
                dp[i][j]=sum;continue;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+sum;
                for(int k=j+1;k<=n;++k)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+sum);
                }
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<=n;++i) {ans=min(ans,dp[n-1][i]);}
    //cout<<ans<<" ans "<<endl;
    return ans;*/
}
int slv0(vector <vector <int> > a,vector <vector <int> > b)
{
    int n=a.size();
    vector <vector <pair<int,int> > > v(n);
    for(int i=0;i<n;++i) {for(int j=0;j<n;++j) v[i].push_back({a[i][j],b[i][j]});}
    int ans=slv1(v);reverse(v.begin(),v.end());ans=min(ans,slv1(v));
    for(int i=0;i<n;++i) reverse(v[i].begin(),v[i].end());
    ans=min(ans,slv1(v));reverse(v.begin(),v.end());ans=min(ans,slv1(v));
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <vector <int> > a(n);vector <vector <int> > b(n);
        for(int i=0;i<n;++i) a[i].resize(n); for(int i=0;i<n;++i) b[i].resize(n);
        int ans=0;
        for(int i=0;i<2*n;++i) for(int j=0;j<2*n;++j)
        {
            int x;cin>>x;if(i>=n && j>=n) ans+=x;
            else if(i>=n && j<n) a[i-n][j]=x;
            else if(i<n && j>=n) b[i][j-n]=x;
        }
        ans+=slv0(a,b);
        cout<<ans<<endl;
    }
    return 0;
}