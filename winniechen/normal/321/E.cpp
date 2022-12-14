#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
#define N 4005
static char buf[1000000],*p1,*p2;
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
#define calc(x,y) (f[x]+((sum[y][y]+sum[x][x]-sum[y][x]-sum[x][y])>>1))
int rd()
{
	register int x=0;register char c=nc();
	while(c<'0'||c>'9')c=nc();
	while(c>='0'&&c<='9')x=(((x<<2)+x)<<1)+c-'0',c=nc();
	return x;
}
int sum[N][N],num[N],k,n,s[N][N];long long f[N];
struct node{int l,r,p;}q[N];
bool cmp(int i,int j,int k)
{
	long long t1=calc(i,k),t2=calc(j,k);
	if(t1==t2)return num[i]<=num[j];
	return t1<t2;
}
int find(const node &t,int x)
{
	int l=t.l,r=t.r+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(cmp(x,t.p,m))r=m;
		else l=m+1;
	}
	return l;
}
int check(int x)
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;int h=0,t=0;q[t++]=(node){1,n,0};num[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(q[h].r<i&&h<t)h++;
		f[i]=calc(q[h].p,i)+x;num[i]=num[q[h].p]+1;
		if(cmp(i,q[t-1].p,n))
		{
			while(h<t&&cmp(i,q[t-1].p,q[t-1].l))t--;
			if(h==t)q[t++]=(node){i+1,n,i};
			else
			{
				int p=find(q[t-1],i);
				q[t-1].r=p-1;
				q[t++]=(node){p,n,i};
			}
		}
	}
	return num[n];
}
int main()
{
	n=rd();k=rd();
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1]+rd();
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			sum[i][j]+=sum[i-1][j];
		}
	}
	int l=0,r=1<<30;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(check(m)>k)l=m+1;
		else r=m;
	}
	check(l);
	printf("%lld\n",f[n]-1ll*l*k);
}