#include<iostream>
#include<cstdio>
#include<map>
#include<cstdlib>
#define mod 1000000007
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
int a[100005][6],w[100005];
int b[100005][6];
int zh[100005];
int sj[1000005];
map<int,int>ma;
int cnt;
int main()
{
	srand(19423);
	int n,m,sth,ans=2147483647;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			if(ma[a[i][j]]==0)ma[a[i][j]]=++cnt;
			b[i][j]=ma[a[i][j]];
		}
		w[i]=read();
	}
	for(int i=1;i<=20;i++)
	{
		for(int i=1;i<=cnt;i++)sj[i]=rand()%15;
		for(int i=0;i<32768;i++)zh[i]=1000000001;
		for(int i=1;i<=n;i++)
		{
			sth=0;
			for(int k=1;k<=m;k++)
			{
				sth|=(1<<sj[b[i][k]]);
			}
		//	printf("%d %d\n",i,sth);
			zh[sth]=min(zh[sth],w[i]);
		}
		for(int i=0;i<32768;i++)
		{
			for(int j=0;j<=14;j++)
			{
				if((i&(1<<j))==0)continue;
				zh[i]=min(zh[i],zh[i^(1<<j)]);
			}
		}
		for(int i=0;i<32768;i++)
		{
			if(zh[i]==1000000001||zh[32767-i]==1000000001)continue;
			ans=min(ans,zh[i]+zh[32767-i]);
		}
	}
	if(ans<=2000000000)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}