#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=205;
int n,m,t,dp[N][N],sz[N],b[N];
string s;
signed main()
{
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!b[s[i]])
			dp[i][1]=1,sz[1]++;
		for(int j=max(0ll,b[s[i]]-1);j<i;j++)
		{
			for(int k=2;k<=i+1;k++)
			{
				dp[i][k]+=dp[j][k-1];
				sz[k]+=dp[j][k-1];
			}
		}
		b[s[i]]=i+1;
	}
	sz[0]=1;
	for(int i=n;i>=0;i--)
	{
		long long x=min(m,sz[i]);
		t+=x*(n-i);
		m-=x;
		if(!m)
			break;
	}
	if(!m)
		cout<<t<<endl;
	else
		cout<<-1<<endl;
	return 0;
}