#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
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
vector<int>v[200005];
map<int,int>ma;
bool vis[200005],inst[2000005];
bool flag;
int a[200005],b[200005];
void dfs(int x)
{
	inst[x]=vis[x]=true;
	for(int i=0;i<v[x].size();i++)
	{
		if(inst[v[x][i]]==true)flag=true;
		if(vis[v[x][i]]==false)dfs(v[x][i]);
	}
	inst[x]=false;
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)v[i].clear(),vis[i]=inst[i]=false;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)v[a[i]].push_back(b[i]);
		int maxn=0;
		for(int i=1;i<=n;i++)if(v[i].size()>v[maxn].size())maxn=i;
		vis[maxn]=true;
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==false)dfs(i);
		}
		if(flag==true)printf("WA\n");
		else printf("AC\n");
	}
	return 0;
}