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
int h[200005],n,k;
int dfs()
{
	for(int i=1;i<=n-1;i++)
	{
		if(h[i]<h[i+1])
		{
			h[i]++;
			return i;
		}
	}
	return -1;
}
int main()
{
	int t;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)h[i]=read();
		flag=false;
		for(int i=1;i<=k-1;i++)
		{
			if(dfs()==-1)
			{
				printf("-1\n");
				flag=true;
				break;
			}
		}
		if(flag==false)printf("%d\n",dfs());
	}
	return 0;
}