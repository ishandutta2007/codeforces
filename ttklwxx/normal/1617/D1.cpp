#include<iostream>
#include<cstdio>
#include<cstring>
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
int ans[200005];
int pt[200005],cnt;
signed main()
{
	int t,n,x,s0,s1;
	bool flag; 
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n-2;i++)
		{
			printf("? %d %d %d\n",i,i+1,i+2);
			fflush(stdout);
			x=read();
			ans[i]=x;
		}
		s0=0;
		s1=0;
		for(int i=1;i<=n-3;i++)
		{
			if(ans[i]>ans[i+1])
			{
				s0=i;
				s1=i+3;
				break;
			}
			if(ans[i]<ans[i+1])
			{
				s0=i+3;
				s1=i;
				break;
			}
		}
		pt[1]=s1;
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(i==s0||i==s1)continue;
			printf("? %d %d %d\n",i,s0,s1);
			fflush(stdout);
			x=read();
			if(x==0)pt[++cnt]=i;
		}
		sort(pt+1,pt+cnt+1);
		printf("! %d ",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",pt[i]);
		printf("\n");
		fflush(stdout);
	} 
	return 0;
}