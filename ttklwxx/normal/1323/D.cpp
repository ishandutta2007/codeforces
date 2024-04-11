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
int a[1000001];
int sa[1000001],sb[1000001],ca,cb;
int main()
{
	int n,ans=0,x,y,tans=0;
	n=read();
	for(register int i=1;i<=n;i++)a[i]=read();
	for(register int jj=0;jj<25;jj++)
	{
		x=(1<<jj);
		ca=0;
		cb=0;
		for(register int i=1;i<=n;i++)
		{
			if(a[i]&x)sa[++ca]=a[i]%x;
			else sb[++cb]=a[i]%x;
		}
		sort(sa+1,sa+ca+1);
		sort(sb+1,sb+cb+1);
		y=cb;
		tans=0;
		for(register int i=1;i<=ca;i++)
		{
			while(y>=1&&sb[y]+sa[i]>=x)y--;
			tans=(tans+y)%2;
		}
		y=ca;
		for(register int i=1;i<=ca;i++)
		{
			while(y>=1&&sa[y]+sa[i]>=x)y--;
			tans=(tans+ca-max(i,y))%2;
		}
		y=cb;
		for(register int i=1;i<=cb;i++)
		{
			while(y>=1&&sb[y]+sb[i]>=x)y--;
			tans=(tans+cb-max(i,y))%2;
		}
		if(tans==1)ans|=x;
	}
	printf("%d\n",ans);
	return 0;
}