#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <algorithm>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
int n,p,m,x[2333333],a[2333333],fst[2333333],nxt[2333333],vb[2333333],M=0,tar[2333333];
bool xx[2333333];
int ys[2333333];
void ad_de(int a,int b) {++M; vb[M]=b; nxt[M]=fst[a]; fst[a]=M;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
int dist[1003][10003],ps[2333333],pn=0,dp[2333333];
template <class T,int siz>
struct sbq
{
	T st[siz+3]; int head,tail,fsiz;
	void clr() {head=tail=fsiz=0;}
	bool empty() {return fsiz==0;}
	int size() {return fsiz;}
	T front() {return st[head];}
	T back() {return st[tail-1];}
	void push(T x) {st[tail++]=x; ++fsiz;}
	void pop() {++head; --fsiz;}
};
sbq<int,100003> q;
void bfs(int a,int* d)
{
	for(int i=0;i<=n;i++) d[i]=-1;
	d[a]=0; q.clr();
	q.push(a);
	while(!q.empty())
	{
		int s=q.front(); q.pop();
		for(int e=fst[s];e;e=nxt[e])
		{
			int b=vb[e];
			if(d[b]!=-1) continue;
			d[b]=d[s]+1; q.push(b);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&p,&m);
	for(int i=1;i<=p;i++) scanf("%d",x+i), xx[x[i]]=1;
	for(int i=0;i<=n;i++) tar[i]=xx[i]^xx[i+1];
	for(int i=0;i<=n;i++) if(tar[i]) ps[++pn]=i;
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	for(int i=0;i<=n;i++)
	{
		for(int k=1;k<=m;k++) if(i+a[k]<=n) adde(i,i+a[k]);
	}
	for(int i=1;i<=pn;i++) bfs(ps[i],dist[i]);
	dp[0]=0;
	for(int i=1;i<=pn;i++) ys[1<<i-1]=i;
	for(int i=1;i<(1<<pn);i++)
	{
		dp[i]=2000000000;
		int ii=i,cnt=0;
		while(ii) cnt+=ii&1, ii>>=1;
		if(cnt&1) continue;
		int j=pn;
		for(;!(i&(1<<j-1));--j);
		for(int k=j-1;k>=1;k--)
		{
			if(i&(1<<k-1));else continue;
			if(dist[j][ps[k]]==-1) continue;
			dp[i]=min(dp[i],dp[i^(1<<j-1)^(1<<k-1)]+dist[j][ps[k]]);
		}
	}
	printf("%d\n",(dp[(1<<pn)-1]==2000000000)?-1:dp[(1<<pn)-1]);
}