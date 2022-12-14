#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define lson l,m,tr[rt].ls
#define rson m+1,r,tr[rt].rs
struct Segment{int ls,rs,mn;Segment(){mn=1<<30;}}tr[N*40];
int rot[N],cnt,n,Q,k;
struct node
{
	int x,y,idx;
	bool operator < (const node &a) const {return a.x==x?a.y==y?idx<a.idx:y<a.y:x<a.x;}
}a[N];
void insert(int x,int v,int c,int l,int r,int &rt)
{
	rt=++cnt;tr[rt]=tr[x];if(l==r){tr[rt].mn=min(tr[rt].mn,c);return ;}int m=(l+r)>>1;
	if(v<=m)insert(tr[x].ls,v,c,lson);else insert(tr[x].rs,v,c,rson);
	tr[rt].mn=max(tr[tr[rt].ls].mn,tr[tr[rt].rs].mn);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return tr[rt].mn;int m=(l+r)>>1,ret=0;
	if(L<=m)ret=query(L,R,lson);if(m<R)ret=max(ret,query(L,R,rson));return ret;
}
int main()
{
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=k;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].idx);
	sort(a+1,a+k+1);
	for(int i=1;i<=n;i++)insert(rot[k+1],i,1<<30,1,n,rot[k+1]);
	for(int i=k;i;i--)insert(rot[i+1],a[i].idx,a[i].y,1,n,rot[i]);
	while(Q--)
	{
		int x,y,c,d;scanf("%d%d%d%d",&c,&d,&x,&y);
		if(a[k].x<x){printf("no\n");fflush(stdout);continue;}
		int p=upper_bound(a+1,a+k+1,(node){x-1,1<<30,1<<30})-a;
		if(query(c,d,1,n,rot[p])>y)printf("no\n");
		else printf("yes\n");fflush(stdout);
	}
}
//