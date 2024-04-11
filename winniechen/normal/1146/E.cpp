#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int tag[N<<3],rev[N<<3],t[N<<3],a[N],n,Q;
inline void giv_rev(int rt){rev[rt]^=1,t[rt]=-t[rt];}
inline void giv_tag(int rt,int v){rev[rt]=0;t[rt]=tag[rt]=v;}
inline void PushDown(int rt)
{
	if(tag[rt])giv_tag(rt<<1,tag[rt]),giv_tag(rt<<1|1,tag[rt]),tag[rt]=0;
	if(rev[rt])giv_rev(rt<<1),giv_rev(rt<<1|1),rev[rt]=0;
}
void build(int l,int r,int rt){t[rt]=(l<0?-1:1);if(l==r)return ;int m=(l+r)>>1;build(lson),build(rson);}
void Update_rev(int L,int R,int l,int r,int rt)
{
	if(L>R)return;if(L<=l&&r<=R)return giv_rev(rt);PushDown(rt);int m=(l+r)>>1;
	if(L<=m)Update_rev(L,R,lson);if(m<R)Update_rev(L,R,rson);
}
void Update_tag(int L,int R,int v,int l,int r,int rt)
{
	if(L>R)return;if(L<=l&&r<=R)return giv_tag(rt,v);PushDown(rt);int m=(l+r)>>1;
	if(L<=m)Update_tag(L,R,v,lson);if(m<R)Update_tag(L,R,v,rson);
}
int query(int p,int l,int r,int rt)
{
	if(l==r)return t[rt];PushDown(rt);int m=(l+r)>>1;
	if(p<=m)return query(p,lson);return query(p,rson);
}
char s[10];
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);build(-1e5,1e5,1);
	for(int x;Q--;)
	{
		scanf("%s%d",s+1,&x);
		if(s[1]=='>')
			if(x>=0)Update_tag(-1e5,-x-1,-1,-1e5,1e5,1),Update_tag(x+1,1e5,-1,-1e5,1e5,1);
			else Update_rev(x+1,-x-1,-1e5,1e5,1),Update_tag(-1e5,x,-1,-1e5,1e5,1),Update_tag(-x,1e5,-1,-1e5,1e5,1);
		else
			if(x<=0)Update_tag(-1e5,x-1,1,-1e5,1e5,1),Update_tag(-x+1,1e5,1,-1e5,1e5,1);
			else Update_rev(-x+1,x-1,-1e5,1e5,1),Update_tag(-1e5,-x,1,-1e5,1e5,1),Update_tag(x,1e5,1,-1e5,1e5,1);
		// for(int i=-5;i<=5;i++)printf("%d ",query(i,-1e5,1e5,1));puts("");
	}
	for(int i=1;i<=n;i++)printf("%d ",query(a[i],-1e5,1e5,1)*abs(a[i]));puts("");
}