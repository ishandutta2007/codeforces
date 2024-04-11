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
	int l,r;
}s[2005];
bool bi(struct sth x,struct sth y)
{
	if(x.l!=y.l)return x.l<y.l;
	return x.r>y.r;
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			s[i].l=read();
			s[i].r=read();
		}
		sort(s+1,s+n+1,bi);
		for(int i=1;i<=n-1;i++)
		{
			if(s[i].l==s[i+1].l)printf("%d %d %d\n",s[i].l,s[i].r,s[i+1].r+1);
			else printf("%d %d %d\n",s[i].l,s[i].r,s[i].l);
		}
		printf("%d %d %d\n",s[n].l,s[n].r,s[n].l);
	} 
	return 0;
}