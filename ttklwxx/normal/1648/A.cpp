#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
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
	int wz,col;
}h[200005],l[200005];
int cnth,cntl;
bool bi(struct sth x,struct sth y)
{
	if(x.col!=y.col)return x.col<y.col;
	else return x.wz<y.wz;
}
signed main()
{
	int n,m,x;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			x=read();
			++cnth;
			++cntl;
			h[cnth].wz=i;
			h[cnth].col=x;
			l[cntl].wz=j;
			l[cntl].col=x;
		}
	}
	sort(h+1,h+cnth+1,bi);
	sort(l+1,l+cntl+1,bi);
	int het=0,sl=0,ans=0;
	for(int i=1;i<=cnth;i++)
	{
		if(i==1||h[i].col!=h[i-1].col)
		{
			het=h[i].wz;
			sl=1;
		}
		else
		{
			het+=h[i].wz;
			sl++;
			ans+=h[i].wz*sl-het;
		}
	}
	het=0;
	sl=0;
	for(int i=1;i<=cntl;i++)
	{
		if(i==1||l[i].col!=l[i-1].col)
		{
			het=l[i].wz;
			sl=1;
		}
		else
		{
			het+=l[i].wz;
			sl++;
			ans+=l[i].wz*sl-het;
		}
	}
	printf("%lld\n",ans);
	return 0;
}