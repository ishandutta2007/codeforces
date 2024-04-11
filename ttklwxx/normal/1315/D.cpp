#include<iostream>
#include<cstdio>
#include<map>
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
	int a,t;
}p[200005];
bool bi(struct sth x,struct  sth y)
{
	if(x.t!=y.t)return x.t>y.t;
	return x.a<y.a;
}
map<int,int>fa;
int findf(int n)
{
	if(fa[n]==0)return n;
	return fa[n]=findf(fa[n]);
}
void merge(int x,int y)
{
	x=findf(x);
	y=findf(y);
	if(x!=y)fa[x]=y;
}
int main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)p[i].a=read();
	for(int i=1;i<=n;i++)p[i].t=read();
	sort(p+1,p+n+1,bi);
	long long ans=0;
	int x;
	for(int i=1;i<=n;i++)
	{
		x=findf(p[i].a);
		ans+=1LL*p[i].t*(x-p[i].a);
		merge(x,x+1);
	}
	printf("%lld\n",ans);
	return 0;
}