#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1000005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int s[N<<2],tag[N<<2];
inline void upd(int rt,int v){s[rt]+=v,tag[rt]+=v;}
inline void PushUp(int rt){s[rt]=max(s[rt<<1],s[rt<<1|1]);}
inline void PushDown(int rt){if(tag[rt])upd(rt<<1,tag[rt]),upd(rt<<1|1,tag[rt]),tag[rt]=0;}
void Update(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return upd(rt,1);PushDown(rt);int m=(l+r)>>1;
	if(L<=m)Update(L,R,lson);if(m<R)Update(L,R,rson);PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return s[rt];PushDown(rt);int m=(l+r)>>1,ret=0;
	if(L<=m)ret=query(L,R,lson);if(m<R)ret=max(ret,query(L,R,rson));return ret;
}
int sta[N],top,pre[N],a[N],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)
	{
		while(top&&a[sta[top]]<=a[i])pre[sta[top]]=i,top--;
		sta[++top]=i;
	}
	for(int i=1;i<=n;i++)
	{
		Update(pre[i]+1,i,1,n,1);
		if(i>=k)printf("%d ",query(i-k+1,i,1,n,1));
	}
	puts("");
}