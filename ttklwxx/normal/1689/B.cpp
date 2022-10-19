#include<iostream>
#include<cstdio>
#include<algorithm>
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
int p[100005];
int nex[100005],pre[100005];
int main()
{
	int ttt,n;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)p[i]=read();
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)nex[i]=i+1,pre[i]=i-1;
		nex[0]=1;
		pre[n+1]=n;
		for(int i=1;i<=n-2;i++)
		{
			if(p[i]!=nex[0])
			{
				printf("%d ",nex[0]);
				int sth=nex[0]; 
				pre[nex[sth]]=pre[sth];
				nex[pre[sth]]=nex[sth];
			}
			else
			{
				printf("%d ",nex[nex[0]]);
				int sth=nex[nex[0]];
				pre[nex[sth]]=pre[sth];
				nex[pre[sth]]=nex[sth];
			}
		}
		int tx=nex[0],ty=nex[nex[0]];
		if(tx!=p[n-1]&&ty!=p[n])printf("%d %d\n",tx,ty);
		else printf("%d %d\n",ty,tx);
	}
	return 0;
}