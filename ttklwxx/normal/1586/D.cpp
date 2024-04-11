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
int p[1005];
int wz[1005];
int main()
{
	int n,x,maxn;
	n=read();
	maxn=n;
	for(int i=n;i>=1;i--)
	{
		if(p[i]>maxn)continue;
		for(int j=2;j<=maxn;j++)
		{
			printf("? ");
			for(int x=1;x<=n;x++)
			{
				if(p[x]>maxn)printf("%d ",n);
				else if(x!=i)printf("%d ",1);
				else printf("%d ",j);
			}
			printf("\n");
			fflush(stdout);
			wz[j]=read();
			if(wz[j]==0)
			{
				p[i]=maxn+2-j;
				for(int x=2;x<=j-1;x++)p[wz[x]]=p[i]+x-1;
				maxn=p[i]-1;
				break;
			}
			if(j==maxn)
			{
				p[i]=1;
				for(int x=2;x<=maxn;x++)p[wz[x]]=p[i]+x-1;
				maxn=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)if(p[i]==0)p[i]=1;
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}