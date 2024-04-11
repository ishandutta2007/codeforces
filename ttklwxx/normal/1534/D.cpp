#include<iostream>
#include<cstdio>
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
int d[2005],on[2005];
int u[2005],v[2005],cnt;
int main()
{
	int n,js=0,os=0;
	n=read();
	printf("? %d\n",1);
	fflush(stdout);
	for(int i=1;i<=n;i++)
	{
		d[i]=read();
		if(d[i]%2==0)os++;
		else js++;
	}
	os--;
	if(os<=js)
	{
		for(int i=1;i<=n;i++)if(d[i]==1)u[++cnt]=1,v[cnt]=i;
		for(int i=2;i<=n;i++)
		{
			if(d[i]%2==1)continue;
			printf("? %d\n",i);
			fflush(stdout);
			for(int j=1;j<=n;j++)
			{
				on[j]=read();
				if(on[j]==1)
				{
					u[++cnt]=i;
					v[cnt]=j;
				}
			} 
		}
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(d[i]%2==0)continue;
			printf("? %d\n",i);
			fflush(stdout);
			for(int j=1;j<=n;j++)
			{
				on[j]=read();
				if(on[j]==1)
				{
					u[++cnt]=i;
					v[cnt]=j;
				}
			} 
		}
	}
	printf("!\n");
	for(int i=1;i<=n-1;i++)printf("%d %d\n",u[i],v[i]);
	fflush(stdout); 
	return 0;
}