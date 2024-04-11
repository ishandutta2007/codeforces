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
int sl[2000001],p[1000001],en[1000001];
int main()
{
	int t,n,g,s,b,k;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int j=1;j<=n;j++)
		{
			p[j]=read();
			sl[p[j]]++;
			if(p[j]!=p[j-1])en[p[j-1]]=j-1;
		}
		en[p[n]]=n;
		g=sl[p[1]];
		s=0;
		for(k=en[p[1]]+1;k<=n;k++)
		{
			s+=sl[p[k]];
			k=en[p[k]];
			if(s>g)break;
		}
		b=0;
		for(k+=1;k<=n;k++)
		{
			if(g+s+b+sl[p[k]]>n/2)break;
			b+=sl[p[k]];
			k=en[p[k]];
		}
		for(int j=1;j<=n;j++)sl[p[j]]--;
		if(s<=g||b<=g||g+s+b>n/2||g==0||b==0||s==0)
		{
			printf("0 0 0\n");
			continue;
		}
		printf("%d %d %d\n",g,s,b);
	}
}