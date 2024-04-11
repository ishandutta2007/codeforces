#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 250005
#define M 10000005
#define ll long long
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
char buf[1000005],*p1,*p2;
inline int rd()
{
	register int x=0;register char c=nc();
	while(c<48)c=nc();while(c>47)x=((x+(x<<2))<<1)+(c^48),c=nc();
	return x;
}
int a[M],sta[M],top,n,m,Q,lst,L[M],R[M];ll val[M],f[M],ans,g[M];
struct node
{
	int siz;
	vector<int >a,v;
	void read()
	{
		siz=rd();a.resize(siz);v.resize(siz);
		for(int i=0;i<siz;i++)a[i]=rd();
		for(int i=0;i<siz;i++)v[i]=rd();
	}
	void copy(int *p,ll *val,int mul){for(int i=0;i<siz;i++)p[i]=a[i],val[i]=(ll)v[i]*mul;}
}b[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)b[i].read();Q=rd();
	int now=1;
	while(Q--)
	{
		int id=rd(),mul=rd();
		b[id].copy(a+now,val+now,mul);now+=b[id].siz;
	}
	top=0;sta[0]=0;
	for(int i=1;i<=m;i++)
	{
		while(top&&i-sta[top]<a[i])top--;
		L[i]=sta[top];sta[++top]=i;
	}
	top=0;sta[0]=m+1;
	for(int i=m;i;i--)
	{
		while(top&&sta[top]-i<a[i])top--;
		R[i]=sta[top];sta[++top]=i;
	}
	top=0;sta[0]=0;
	for(int i=1;i<=m;i++)
	{
		while(top&&R[sta[top]]<=i)top--;
		ll tmp=1ll<<60;if(top)tmp=g[sta[top]];
		tmp=min(tmp,f[L[i]]+val[i]);f[i]=tmp;
		g[i]=f[i-1]+val[i];
		while(top&&R[sta[top]]==R[i]&&g[i]<g[sta[top]])top--;
		if(!top||g[i]<g[sta[top]])sta[++top]=i;
	}
	printf("%lld\n",f[m]);
}
// mlogn