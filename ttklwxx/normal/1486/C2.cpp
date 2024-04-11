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
int ql[200005],qr[200005],ans[200005],cnt;
int main()
{
	int n;
	n=read();
	if(n==1)
	{
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	int l=1,r=n,mid;
	printf("? %d %d\n",1,n);
	fflush(stdout);
	ql[++cnt]=1;
	qr[cnt]=n;
	ans[cnt]=read();
	int sth=ans[1];
	while(l!=r)
	{
		mid=(l+r)>>1;
		if(sth<=mid)
		{
		if(mid==1)
		{
			l=mid+1;
			continue;
		}
		printf("? %d %d\n",1,mid);
		fflush(stdout);
		ql[++cnt]=1;
		qr[cnt]=mid;
		ans[cnt]=read();
		if(ans[cnt]==sth)r=mid;
		else l=mid+1;
		}
		else
		{
		if(mid+1==n)
		{
			r=mid;
			continue;
		}
		printf("? %d %d\n",mid+1,n);
		fflush(stdout);
		ql[++cnt]=mid+1;
		qr[cnt]=n;
		ans[cnt]=read();
		if(ans[cnt]==sth)l=mid+1;
		else r=mid;
		}
	}
	printf("! %d\n",l);
	return 0;
}