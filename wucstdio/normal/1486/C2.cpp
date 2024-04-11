#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ask(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int p;
	scanf("%d",&p);
	return p;
}
int n;
void solve(int l,int r,int p)
{
	if(l==r)
	{
		printf("! %d\n",l);
		exit(0);
	}
	if(l==r-1)
	{
		printf("! %d\n",p==l?r:l);
		exit(0);
	}
	if(l==r-2)
	{
		if(p==l)
		{
			if(ask(l,l+1)==p)printf("! %d\n",l+1);
			else printf("! %d\n",r);
		}
		else
		{
			if(ask(r-1,r)==p)printf("! %d\n",p==r?r-1:r);
			else printf("! %d\n",l);
		}
		exit(0);
	}
	int mid=(l+r)>>1;
	if(p<=mid)
	{
		if(ask(l,mid)==p)solve(l,mid,p);
		else
		{
			int ll=mid+1,rr=r;
			while(ll<rr)
			{
				int m=(ll+rr)>>1;
				if(ask(l,m)==p)rr=m;
				else ll=m+1;
			}
			printf("! %d\n",ll);
			exit(0);
		}
	}
	else
	{
		if(ask(mid+1,r)==p)solve(mid+1,r,p);
		else
		{
			int ll=l,rr=mid;
			while(ll<rr)
			{
				int m=(ll+rr+1)>>1;
				if(ask(m,r)==p)ll=m;
				else rr=m-1;
			}
			printf("! %d\n",ll);
			exit(0);
		}
	}
}
int main()
{
	scanf("%d",&n);
	int p=ask(1,n);
	solve(1,n,p);
	return 0;
}