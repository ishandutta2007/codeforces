#include<bits/stdc++.h>
using namespace std;
char s[205];
int n,a[26][26],d[26],vis[26];
vector<int>p;
void dfs(int u,int f)
{
	p.push_back(u);
	vis[u]=1;
	for(int i=0;i<26;i++)
		if(a[u][i]&&i!=f)
			dfs(i,u);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<26;i++)
		{
			d[i]=vis[i]=0;
			for(int j=0;j<26;j++)
				a[i][j]=0;
		}
		for(int i=2;i<=n;i++)
		{
			int u=s[i]-'a',v=s[i-1]-'a';
			a[u][v]=a[v][u]=1;
		}
		int flag=1;
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
				d[i]+=a[i][j];
			if(d[i]>2)
				flag=0;
		}
		if(!flag)
		{
			puts("NO");
			continue;
		}
		vector<int>ans;
		for(int i=0;i<26;i++)
		{
			if(d[i]==1&&!vis[i])
			{
				p.clear();
				dfs(i,-1);
				for(auto c:p)
					ans.push_back(c);
			}
			if(d[i]==0)
				ans.push_back(i),vis[i]=1;
		}
		for(int i=0;i<26;i++)
			if(!vis[i])
				flag=0;
		if(!flag)
			puts("NO");
		else
		{
			puts("YES");
			for(auto c:ans)
				printf("%c",c+'a');
			puts("");
		}
	}
	return 0;
}