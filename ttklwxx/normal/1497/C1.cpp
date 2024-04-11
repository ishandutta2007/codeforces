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
int sl=1;
void dfs(int n,int k)
{
	if(n%2==1)
	{
		printf("%d %d %d\n",sl,(n-1)/2*sl,(n-1)/2*sl);
		return;
	}
	sl*=2;
	dfs(n/2,k);
}
int main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		sl=1;
		if(n%4==0)
		{
			printf("%d %d %d\n",n/4,n/4,n/2);
			continue;
		}
		dfs(n,k);
	}
	return 0;
}