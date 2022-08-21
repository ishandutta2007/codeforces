//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m,k,x[2333333],pos[2333333],cp[2333333],pre[2333333];
long long ans[2333333],curans=0;
struct cq {int l,r,id,fid;}q[2333333];
bool operator < (cq a,cq b)
{
	if(a.fid!=b.fid) return a.l<b.l;
	return a.r<b.r;
}
void upda(int a)
{
	curans+=cp[pre[a]^k];
	cp[pre[a]]++;
}
void updd(int a)
{
	cp[pre[a]]--;
	curans-=cp[pre[a]^k];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int sq=sqrt(n)+1e-6;
	for(int i=1;i<=n;i++) scanf("%d",x+i),pos[i]=(i-1)/sq;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^x[i];
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r); --q[i].l;
		q[i].id=i; q[i].fid=pos[q[i].l];
	}
	sort(q+1,q+1+m);
	int cl=0,cr=-1;
	for(int i=1;i<=m;i++)
	{
		int l=q[i].l,r=q[i].r;
		if(l==r) {ans[q[i].id]=0; continue;}
		while(cl<l) updd(cl++);
		while(cl>l) upda(--cl);
		while(cr>r) updd(cr--);
		while(cr<r) upda(++cr);
		ans[q[i].id]=curans;
	}
	for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
}