#include <bits/stdc++.h> 

using namespace std; 
#define int long long 
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	vector <int> v0;vector <int> v1;
	for(int i=0;i<n;++i) {cin>>a[i];if(!a[i]) v0.push_back(i);else v1.push_back(i);}
	int dp[v1.size()+1][v0.size()+1];
    for(int i=0;i<=v1.size();++i)
    {
    	for(int j=0;j<=v0.size();++j)
    	{
    		dp[i][j]=0;
    		if(i!=v1.size() && j==v0.size()) 
    		{
    			dp[i][j]=1e18;
    		}
    	}
    }
    for(int i=v1.size()-1;i>=0;i--)
    {
    	for(int j=v0.size()-1;j>=0;--j) 
    	{
    		dp[i][j]=min(dp[i][j+1],dp[i+1][j+1]+abs(v0[j]-v1[i]));
    	}
    }
    cout<<dp[0][0];
	return 0;
}