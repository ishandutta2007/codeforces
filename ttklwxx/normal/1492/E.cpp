#include<bits/stdc++.h>
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
int tans[300005];
vector<int>a[300005];
int sl[300005],n,m;
void dfs(int x)
{
	//printf("orz%d\n",x);
	//for(int i=1;i<=m;i++)printf("%d ",tans[i]);
	//printf("\n");
	int sth=0;
	for(int i=1;i<=n;i++)
	{
		sl[i]=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=tans[j])sl[i]++;
		}
		if(x==0&&sl[i]>4)
		{
			printf("No\n");
			exit(0);
		}
		if(sl[i]>4)return;
		if(sl[i]>2)sth=i;
	}
	if(sth==0)
	{
		printf("Yes\n");
		for(int i=1;i<=m;i++)printf("%d ",tans[i]);
		printf("\n");
		exit(0);
	}
	if(x==2)return;
	int now[15],cnt=0;
	for(int i=1;i<=m;i++)if(a[sth][i]!=tans[i])now[++cnt]=i;
	for(int i=1;i<=cnt;i++)
	{
		int gre=tans[now[i]];
		tans[now[i]]=a[sth][now[i]];
		dfs(x+1);
		tans[now[i]]=gre;
	}
} 
int main()
{
	int x,sth=0;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			x=read();
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++)
	{
		tans[i]=a[1][i];
	}
	dfs(0);
	printf("No\n");
	return 0;
}