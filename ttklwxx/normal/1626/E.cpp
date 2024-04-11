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
int col[400005];
int siz[400005];
int zs;
vector<int>v1[400005],v2[400005];
int ans[400005];
void dfs(int x,int f)
{
	siz[x]=col[x]; 
	for(int i=0;i<v1[x].size();i++)
	{
		if(v1[x][i]==f)continue;
		dfs(v1[x][i],x);
		siz[x]+=siz[v1[x][i]];
		if(siz[v1[x][i]]>=2)v2[v1[x][i]].push_back(x);
		if(siz[v1[x][i]]<=zs-2)v2[x].push_back(v1[x][i]);
	}
}
void dfs2(int x,int f)
{
	ans[x]=1;
	for(int i=0;i<v2[x].size();i++)
	{
		if(ans[v2[x][i]]==0)dfs2(v2[x][i],x);
	}
}
int main()
{
	int n,x,y;
	n=read();
	for(int i=1;i<=n;i++)col[i]=read(),zs+=col[i];
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		v1[x].push_back(y);
		v1[y].push_back(x);
	} 
	dfs(1,0);
	bool flag;
	for(int i=1;i<=n;i++)
	{
		if(col[i]==1)dfs2(i,0);
		else
		{
			flag=false;
			for(int j=0;j<v1[i].size();j++)
			{
				//printf("%d ",v1[i][j]);
				if(col[v1[i][j]]==1)
				{
					flag=true;
					break;
				}
			}
			//printf("\n");
			if(flag==true)dfs2(i,0);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}