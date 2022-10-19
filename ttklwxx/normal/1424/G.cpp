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
struct sth
{
	int t,j;
}a[800004];
bool bi(struct sth x,struct sth y)
{
	if(x.t!=y.t)return x.t<y.t;
	else return x.j<y.j;
}
int main()
{
	int n,maxn=0,now=0,mpos=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[2*i-1].t=read();
		a[2*i-1].j=1;
		a[2*i].t=read();
		a[2*i].j=-1;
	}
	sort(a+1,a+2*n+1,bi);
	for(int i=1;i<=2*n;i++)
	{
		now+=a[i].j;
		if(now>maxn)
		{
			maxn=now;
			mpos=a[i].t;
		}
	}
	printf("%d %d\n",mpos,maxn);
	return 0;
}