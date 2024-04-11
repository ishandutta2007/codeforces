#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char ans[200005];
vector<int>v1[200005],v2[200005];
int vis1[200005],vis2[200005];
bool dfs1(int x)
{
	vis1[x]=-1;
	for(int i=0;i<v1[x].size();i++)
	{
		if(vis1[v1[x][i]]<0)return 0;
		else if(vis1[v1[x][i]]==0&&dfs1(v1[x][i])==0)return 0;
	}
	vis1[x]=1;
	return 1;
}
bool dfs2(int x)
{
	vis2[x]=-1;
	for(int i=0;i<v2[x].size();i++)
	{
		if(vis2[v2[x][i]]<0)return 0;
		else if(vis2[v2[x][i]]==0&&dfs2(v2[x][i])==0)return 0;
	}
	vis2[x]=1;
	return 1;
}
int main()
{
	int n,m,x,y;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	x=0;
	for(int i=1;i<=n;i++)
	{
		if(vis1[i]==0&&vis2[i]==0)ans[i]='A',x++;
		else ans[i]='E';
		if(dfs1(i)==0||dfs2(i)==0)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n%s\n",x,ans+1);
	return 0;
}