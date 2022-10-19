#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,x,k,dp[N][N],ch[N][10],a[N*10],zh,f[N];
char s[N];
vector<int>v;
queue<int>q;
void add()
{
	int u=0;
	for(auto i:v)
	{
		if(!ch[u][i])
			ch[u][i]=++k;
		u=ch[u][i];
	}
	a[u]=1;
}
void dfs()
{
	if(v.size()&&zh==x)
		add();
	if(zh>=x)
		return;
	for(int i=1;i<10;i++)
	{
		if(x!=i&&x%i==0)
			continue;
		int s=i,fl=1;
		for(int j=v.size()-1;j>=0;j--)
		{
			s+=v[j];
			if(x!=s&&x%s==0)
			{
				fl=0;
				break;
			}
		}
		if(fl)
		{
			v.push_back(i);
			zh+=i;
			dfs();
			v.pop_back();
			zh-=i;
		}
	}
}
int main()
{
	scanf("%s%d",s+1,&x);
	n=strlen(s+1);
	dfs();
	for(int i=1;i<10;i++)
	{
		if(ch[0][i])
		{
			f[ch[0][i]]=0;
			q.push(ch[0][i]);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		a[u]|=a[f[u]];
		for(int i=1;i<10;i++)
		{
			if(ch[u][i])
			{
				f[ch[u][i]]=ch[f[u]][i];
				q.push(ch[u][i]);
			}
			else
				ch[u][i]=ch[f[u]][i];
		}
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=1e9;
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(dp[i][j]>=1e9)
				continue;
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
			if(!a[ch[j][s[i+1]-'0']])
				dp[i+1][ch[j][s[i+1]-'0']]=min(dp[i+1][ch[j][s[i+1]-'0']],dp[i][j]);
		}
	}
	int ans=1e9;
	for(int i=0;i<=k;i++)
		ans=min(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}