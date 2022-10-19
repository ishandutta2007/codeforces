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
	while(r-l>1)
	{
		if(ql[cnt]!=l||qr[cnt]!=r)
		{
			printf("? %d %d\n",l,r);
			fflush(stdout);
			ql[++cnt]=l;
			qr[cnt]=r;
			ans[cnt]=read();
		}
		mid=(l+r)>>1;
		if(ans[cnt]<=mid)
		{
		if(l==mid)
		{
			l=mid+1;
			continue;
		}
		printf("? %d %d\n",l,mid);
		fflush(stdout);
		ql[++cnt]=l;
		qr[cnt]=mid;
		ans[cnt]=read();
		if(ans[cnt]==ans[cnt-1])r=mid;
		else l=mid+1;
		}
		else
		{
		if(mid+1==r)
		{
			r=mid;
			continue;
		}
		printf("? %d %d\n",mid+1,r);
		fflush(stdout);
		ql[++cnt]=mid+1;
		qr[cnt]=r;
		ans[cnt]=read();
		if(ans[cnt]==ans[cnt-1])l=mid+1;
		else r=mid;
		}
	}
	if(l==r)
	{
		printf("! %d\n",l);
		fflush(stdout);
		return 0;
	}
	if(ql[cnt]!=l||qr[cnt]!=r)
	{
		printf("? %d %d\n",l,r);
		fflush(stdout);
		ql[++cnt]=l;
		qr[cnt]=r;
		ans[cnt]=read();
	}
	printf("! %d\n",l+r-ans[cnt]);
	fflush(stdout);
	return 0;
}