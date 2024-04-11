#include<bits/stdc++.h>
using namespace std;
const int N=200005;
map<int,int>c;
vector<int>a;
int dp[N*2];
int main() 
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		int x;
		cin>>x;
		c[x]++;
	}
	for(auto i:c)
		a.push_back(i.second);
	sort(a.begin(),a.end());
	n=a.size();
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int x=1;x<=a[i];x++)
		{
			dp[x]=max(dp[x],x+dp[x*2]);
			ans=max(ans,dp[x]);
		}
	}
	cout<<ans<<endl;
	return 0;
}