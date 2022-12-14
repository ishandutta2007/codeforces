#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 20005
#define ll long long
const int inf = 0x3f3f3f3f;

struct node
{
	int K,B;
	node(){}
	node(int a,int b){K=a,B=b;}
	int get(int x){return K*x+B;}
}sta[N];
inline bool cmp(const node &a,const node &b,const node &c){return (ll)(a.K-b.K)*(c.B-a.B)<=(ll)(a.K-c.K)*(b.B-a.B);}
int top;
void insert(node x)
{
	while(top&&x.K>=sta[top].K)x.B=min(x.B,sta[top].B),top--;
	while(top>1&&cmp(sta[top-1],sta[top],x))top--;sta[++top]=x;
}
int get(int x)
{
	if(!top)return inf;
	int l=1,r=top;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(sta[m].get(x)<=sta[m+1].get(x))r=m;else l=m+1;
	}return sta[l].get(x);
}
int n,K,a[N],f[N],g[N],pmx[N],smx[N];
void solve(int l,int r)
{
	if(l==r)return ;int m=(l+r)>>1;solve(l,m),solve(m+1,r);
	smx[m+1]=0;for(int i=m;i>=l;i--)smx[i]=max(smx[i+1],a[i]);
	pmx[m]=0;for(int i=m+1;i<=r;i++)pmx[i]=max(pmx[i-1],a[i]);
	top=0;int p=l;
	for(int i=r;i>m;i--)
	{
		while(p<=m&&smx[p+1]>=pmx[i])
			if(g[p++]<inf)insert(node(smx[p],g[p-1]-(p-1)*smx[p]));
		f[i]=min(f[i],get(i));
	}
	top=0;p=m;
	for(int i=m+1;i<=r;i++)
	{
		while(p>=l&&smx[p+1]<=pmx[i])
			if(g[p--]<inf)insert(node(p+1,g[p+1]));
		f[i]=min(f[i],get(-pmx[i])+i*pmx[i]);
	}
}

int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pmx[i]=max(pmx[i-1],a[i]);
	for(int i=1;i<=n;i++)f[i]=pmx[i]*i;
	for(int i=2;i<=K;i++)memcpy(g,f,sizeof(g)),memset(f,0x3f,sizeof(f)),solve(1,n);
	printf("%d\n",f[n]);
}