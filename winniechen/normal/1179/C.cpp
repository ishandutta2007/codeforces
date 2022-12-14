#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000001;
int tag[N<<3],mn[N<<3];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void giv(int rt,int v){tag[rt]+=v,mn[rt]+=v;}
void PushDown(int rt){if(tag[rt])giv(rt<<1,tag[rt]),giv(rt<<1|1,tag[rt]),tag[rt]=0;}
void PushUp(int rt){mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);}
void Update(int L,int R,int v,int l,int r,int rt)
{
	if(L<=l&&r<=R)return giv(rt,v);PushDown(rt);int m=(l+r)>>1;
	if(L<=m)Update(L,R,v,lson);if(m<R)Update(L,R,v,rson);PushUp(rt);
}
int query(int l,int r,int rt)
{
	PushDown(rt);if(mn[rt]>=0)return -1;if(l==r)return l;int m=(l+r)>>1;
	if(mn[rt<<1|1]>=0)return query(lson);return query(rson);
}
int a[N],b[N],n,m,Q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),Update(1,a[i],-1,1,1000000,1);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),Update(1,b[i],1,1,1000000,1);
	scanf("%d",&Q);
	while(Q--)
	{
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op==1)
			Update(1,a[x],1,1,1000000,1),
			Update(1,y,-1,1,1000000,1),a[x]=y;
		else 
			Update(1,b[x],-1,1,1000000,1),
			Update(1,y,1,1,1000000,1),b[x]=y;
		printf("%d\n",query(1,1000000,1));
	}
}