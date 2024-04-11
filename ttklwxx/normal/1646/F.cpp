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
vector<int>v[200005];
int zy[200005];
vector<int>ans[200005];
int c[105][105],sl[105][105];
int main()
{
	int n,tsl=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=read();
			sl[i][c[i][j]]++;
			if(sl[i][c[i][j]]>1)v[i].push_back(c[i][j]);
		}
	}
	bool flag;
	int sth,gre;
	while(1)
	{
		flag=true;
		sth=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i].size()!=0)
			{
				flag=false;
				sth=i;
				break;
			}
		}
		if(flag==true)break;
		int lc=-1;
		for(int i=sth;i<=sth+n-1;i++)
		{
			gre=(i-1)%n+1;
			if(v[gre].size()!=0)
			{
				lc=v[gre].back();
				v[gre].pop_back();
			}
			zy[gre]=lc;
		}
		for(int i=1;i<=n;i++)
		{
			gre=i%n+1;
			sl[i][zy[i]]--;
			sl[gre][zy[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			gre=i%n+1;
			if(sl[gre][zy[i]]>1)v[gre].push_back(zy[i]);
		}
		tsl++;
		//printf("orz\n");
		//for(int i=1;i<=n;i++)printf("%d ",zy[i]);
		//printf("\n");
		for(int i=1;i<=n;i++)ans[i].push_back(zy[i]);
	}
	for(int j=1;j<n;j++)
	{
		tsl+=j;
		for(int i=1;i<=n;i++)
		{
			zy[i]=(i-j-1+2*n)%n+1;
			for(int k=1;k<=j;k++)ans[i].push_back(zy[i]);
		}
	}
	printf("%d\n",tsl);
	for(int i=0;i<tsl;i++)
	{
		for(int j=1;j<=n;j++)printf("%d ",ans[j][i]);
		printf("\n");
	}
	return 0;
}