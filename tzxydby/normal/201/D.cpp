#include<bits/stdc++.h>
using namespace std;
const int N=20,M=50005,K=305;
map<string,int>mp;
int n,m,dp[M][K],a1=-1,a2=1e9,nxt[N][M*10];
string s[N],str;
vector<int>a[N];
void sol(int x)
{
	int k=a[x].size();
	for(int i=0;i<n;i++)
	{
		nxt[i][k]=k;
		for(int j=k-1;j>=0;j--)
		{
			nxt[i][j]=nxt[i][j+1];
			if(a[x][j]==i)
				nxt[i][j]=j;
		}
	}
	for(int s=0;s<(1<<n);s++)
		for(int i=0;i<=n*n;i++)
			dp[s][i]=1e9;
	dp[0][0]=0;
	for(int s=0;s<(1<<n);s++)
	{
		for(int i=0;i<=n*n;i++)
		{
			if(dp[s][i]>=k)
				continue;
			for(int j=0;j<n;j++)
			{
				if(s&(1<<j))
					continue;
				int v=nxt[j][dp[s][i]];
				if(v==k)
					continue;
				int c=0;
				for(int k=j+1;k<n;k++)
					if(s&(1<<k))
						c++;
				dp[s|(1<<j)][i+c]=min(dp[s|(1<<j)][i+c],v+1);
			}
		}
	}
	for(int i=0;i<=n*n;i++)
	{
		if(dp[(1<<n)-1][i]<1e8)
		{
			if(i<a2)
			{
				a1=x+1;
				a2=i;
			}
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		mp[s[i]]=i;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>str;
			int id=-1;
			if(mp.find(str)!=mp.end())
				id=mp[str];
			if(id!=-1)
				a[i].push_back(id);
		}
	}
	for(int i=0;i<m;i++)
		sol(i);
	if(a1==-1)
	{
		cout<<"Brand new problem!"<<endl;
		return 0;
	}
	a2=n*(n-1)/2-a2+1;
	cout<<a1<<endl<<"[:";
	for(int i=1;i<=a2;i++)
		cout<<"|";
	cout<<":]"<<endl;
	return 0;
}