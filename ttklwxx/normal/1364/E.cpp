#include<iostream>
#include<cstdio>
#include<cstdlib>
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
int md[11];
int get(int x)
{
	int ans=0,sth;
	for(int i=0;i<=10;i++)
	{
		if(md[i]==x)continue;
		printf("? %d %d\n",x,md[i]);
		fflush(stdout);
		sth=read();
		if(sth&(1<<i))ans|=(1<<i);
	}
	return ans;
}
int p[10005];
int main()
{
	int n,sl=0,x,y,ans;
	n=read();
	while(sl<11)
	{
		x=rand()%n+1;
		y=rand()%n+1;
		while(y==x)
		{
			x=rand()%n+1;
			y=rand()%n+1;
		}
		printf("? %d %d\n",x,y);
		fflush(stdout);
		ans=read();
		for(int i=10;i>=0;i--)
		{
			if(ans&(1<<i))continue;
			if(md[i]==0)
			{
				md[i]=x;
				sl++;
			}
		}
	}
	//printf("!!!\n");
	int id=1,val=get(1);
	for(int i=2;i<=n;i++)
	{
		printf("? %d %d\n",id,i);
		//printf("orz\n");
		fflush(stdout);
		ans=read();
		if(ans==val)
		{
			id=i;
			val=get(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=id)
		{
			printf("? %d %d\n",id,i);
			fflush(stdout);
			ans=read();
			p[i]=ans;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}