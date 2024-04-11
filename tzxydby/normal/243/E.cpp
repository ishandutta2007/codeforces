#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int n,a[N][N],sr[N],sc[N],od[N],vis[N],p[N],c[N];
char b[N];
bool cmp(int x,int y){return sc[x]<sc[y];}
void dfs(int x)
{
	if(x==n+1)
	{
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d",a[i][p[j]]);
			puts("");
		}
		exit(0);
	}
	for(int h=1;h<=n;h++)
	{
		int j=od[h],fl=1;
		if(vis[j])
			continue;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j])
				continue;
			if(c[i]&&c[i]!=sr[i])
			{
				fl=0;
				break;
			}
		}
		if(!fl)
			continue;
		p[x]=j;
		vis[j]=1;
		for(int i=1;i<=n;i++)
			if(a[i][j])
				c[i]++;
		dfs(x+1);
		p[x]=0;
		vis[j]=0;
		for(int i=1;i<=n;i++)
			if(a[i][j])
				c[i]--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",b+1);
		for(int j=1;j<=n;j++)
			a[i][j]=(b[j]=='1'),sr[i]+=a[i][j],sc[j]+=a[i][j];
	}
	for(int j=1;j<=n;j++)
		od[j]=j;
	sort(od+1,od+n+1,cmp);
	dfs(1);
	puts("NO");
	return 0;
}