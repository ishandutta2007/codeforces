#include<bits/stdc++.h>
using namespace std;
const int N=60,M=2100;
int n,mp[M],p[N][N][2],dp[N][M],pd[N][M],pt[N][M],ans,pa;
char s[N],sq[M];
int dfs(int c,int s)
{
	int &f=dp[c][s];
	if(f!=-1)
		return f;
	f=0;
	for(int d=0;d<52;d++)
	{
		int t=0,g=1;
		for(int i=0;i<n;i++)
		{
			int v=p[i][c][s>>i&1];
			if(p[i][d][0]>v)
				t|=(0<<i);
			else if(p[i][d][1]>v)
				t|=(1<<i);
			else
				g=0;
		}
		if(g)
		{
			int v=dfs(d,t)+1;
			if(v>f)
			{
				f=v;
				pd[c][s]=d;
				pt[c][s]=t;
			}
		}
	}
	return f;
}
void sol()
{
	scanf("%d",&n);
	memset(p,0,sizeof(p));
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(int j=1;j<=l;j++)
		{
			int x=mp[s[j]];
			if(!p[i][x][0])
				p[i][x][0]=j;
			else
				p[i][x][1]=j;
		}
	}
	ans=0;
	for(int d=0;d<52;d++)
	{
		int g=1;
		for(int i=0;i<n;i++)
			if(!p[i][d][0])
				g=0;
		if(g)
		{
			int v=dfs(d,0)+1;
			if(v>ans)
			{
				ans=v;
				pa=d;
			}
		}
	}
	printf("%d\n",ans);
	int d=pa,t=0;
	for(int i=1;i<=ans;i++)
	{
		printf("%c",sq[d]);
		int nd=pd[d][t],nt=pt[d][t];
		d=nd,t=nt;
	}
	puts("");
	
}
int main()
{
	for(int i=0;i<26;i++)
		mp['a'+i]=i,sq[i]='a'+i;
	for(int i=0;i<26;i++)
		mp['A'+i]=26+i,sq[26+i]='A'+i;
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}