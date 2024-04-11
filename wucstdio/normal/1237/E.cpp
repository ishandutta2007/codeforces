#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,f[2000005];
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	f[1]=(n&1);
	for(int i=2;i<=n;i++)
	{
		if(i&1)
		{
			f[i*2]=1;
			if(f[i]!=-1)f[i*2+1]=f[i]^f[i*2]^1;
		}
		else
		{
			f[i*2+1]=0;
			if(f[i]!=-1)f[i*2]=f[i]^f[i*2+1]^1;
		}
	}
	int x=1;
	while(x*2-1<=n)x=x*2;
	int num=x-1;
	for(int i=x/2;i<x;i++)
	  if(f[i]==0||i==x-1)num++;
	if(n==num||n==num+1)printf("1\n");
	else printf("0\n");
	return 0;
}