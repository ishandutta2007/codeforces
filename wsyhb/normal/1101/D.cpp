#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
char buffer[100001],*S,*T;
inline char read_char()
{
	if(S==T)
	{
		T=(S=buffer)+fread(buffer,1,100001,stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline int read_int()
{
	int s=0;
	bool flag=false;
	char c=read_char();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=true;
		c=read_char();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c-'0');
		c=read_char();
	}
	return flag?-s:s;
}
const int N=2e5+5;
const int A=2e5+5;
int a[N];
int p[90]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443};
vector<int> edge[N];
int dfn[N],id[N],f[N];
int t;
void dfs(int x,int fa)
{
	dfn[x]=++t;
	id[t]=x;
	f[t]=dfn[fa];
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa) dfs(y,x);
	}
}
vector<int> node[A];
int pos[A],s[A];
bool cmp_pos(int x,int y)
{
	return s[x]>s[y];
}
bool cmp(int x,int y)
{
	return x>y;
}
int dp[N][2];
int main()
{
	int n=read_int();
	for(int i=1;i<=n;i++) a[i]=read_int();
	for(int i=1;i<n;i++)
	{
		int x=read_int(),y=read_int();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		int x=a[id[i]];
		for(int j=1;j<=86&&p[j]*p[j]<=x;j++)
			if(x%p[j]==0)
			{
				node[p[j]].push_back(i);
				while(x%p[j]==0) x/=p[j];
			}
		if(x!=1) node[x].push_back(i);
	}
	for(int i=1;i<=n;i++) edge[i].clear();
	for(int i=1;i<=2e5;i++)
	{
		s[i]=node[i].size();
		pos[i]=i;
	}
	sort(pos+1,pos+200000+1,cmp_pos);
	int ans=0;
	for(int p=1;p<=2e5;p++)
	{
		int i=pos[p];
		if(s[i]<=ans) break;
		sort(node[i].begin(),node[i].end(),cmp);
		for(int j=0;j<node[i].size();j++)
		{
			int x=node[i][j];
			dp[x][0]=dp[x][1]=1;
			for(int k=0;k<edge[x].size();k++)
			{
				int son=edge[x][k];
				if(dp[x][0]<dp[son][0]+1)
				{
					dp[x][1]=dp[x][0];
					dp[x][0]=dp[son][0]+1;
				}
				else if(dp[x][1]<dp[son][0]+1) dp[x][1]=dp[son][0]+1;
				else if(dp[x][0]<dp[son][1]+1)
				{
					dp[x][1]=dp[x][0];
					dp[x][0]=dp[son][1]+1;
				}
				else if(dp[x][1]<dp[son][1]+1) dp[x][1]=dp[son][1]+1;
			}
			edge[f[x]].push_back(x);
		}
		for(int j=0;j<node[i].size();j++) ans=max(ans,dp[node[i][j]][0]+dp[node[i][j]][1]-1);
		for(int j=0;j<node[i].size();j++)
		{
			int x=node[i][j];
			int fa=f[x];
			dp[x][0]=dp[x][1]=dp[fa][0]=dp[fa][1]=0;
			edge[fa].clear();
		}
	}
	printf("%d",ans);
	return 0;
}