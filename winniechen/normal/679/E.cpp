#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int n,Q,a[N];ll b[15];

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll mx[N<<2],tag[N<<2],s[N<<2],cov[N<<2];
bool is_leaf[N<<2];int sam[N<<2];
void PushUp(int rt)
{
	mx[rt] = max(mx[rt<<1],mx[rt<<1|1]);
	sam[rt] = sam[rt<<1]&sam[rt<<1|1]&(s[rt<<1]==s[rt<<1|1]);
	s[rt] = s[rt<<1];
}
void giv(int rt,ll v)
{
	if(is_leaf[rt])
		s[rt] += v , mx[rt] = s[rt]-*(lower_bound(b,b+10,s[rt]));
	else mx[rt] += v , tag[rt] += v , s[rt] += v;
}
void giv_cov(int rt,ll v)
{
	s[rt]=v,mx[rt]=v-*(lower_bound(b,b+10,v));
	tag[rt]=0,cov[rt]=v,sam[rt]=1;
}
void PushDown(int rt)
{
	if(cov[rt]) giv_cov(rt<<1,cov[rt]) , giv_cov(rt<<1|1,cov[rt]), cov[rt] = 0;
	if(tag[rt]) giv(rt<<1,tag[rt]) , giv(rt<<1|1,tag[rt]) , tag[rt] = 0;
}
void build(int l,int r,int rt)
{
	if(l==r)return is_leaf[rt] = 1 , giv_cov(rt,a[l]); 
	int m=(l+r)>>1;build(lson),build(rson),PushUp(rt);
}
void Update_cov(int L,int R,ll v,int l,int r,int rt)
{
	if(L<=l&&r<=R)return giv_cov(rt,v);int m=(l+r)>>1;PushDown(rt);
	if(L<=m)Update_cov(L,R,v,lson);if(m<R)Update_cov(L,R,v,rson);PushUp(rt);
}
void Update(int L,int R,int v,int l,int r,int rt)
{
	if(sam[rt])return Update_cov(L,R,v+s[rt],l,r,rt);
	if((L<=l&&r<=R&&mx[rt]+v<0)||(is_leaf[rt]))return giv(rt,v);
	int m=(l+r)>>1;PushDown(rt);
	if(L<=m)Update(L,R,v,lson);if(m<R)Update(L,R,v,rson);PushUp(rt);
}
ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return mx[rt];int m=(l+r)>>1;ll ret=-1;PushDown(rt);
	if(L<=m)ret=query(L,R,lson);if(m<R)ret=max(ret,query(L,R,rson));return ret;
}
ll query(int p,int l,int r,int rt)
{
	if(l==r)return s[rt];PushDown(rt);int m=(l+r)>>1;
	if(p<=m)return query(p,lson);return query(p,rson);
}
int main()
{
	b[0] = 1;for(int i=1;i<10;i++)b[i] = b[i-1]*42;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);build(1,n,1);
	for(int op,l,r,x;Q--;)
	{
		scanf("%d",&op);
		if(op==1)scanf("%d",&x),printf("%lld\n",query(x,1,n,1));
		else if(op==2)scanf("%d%d%d",&l,&r,&x),Update_cov(l,r,x,1,n,1);
		else 
		{
			scanf("%d%d%d",&l,&r,&x);Update(l,r,x,1,n,1);
			// printf("%lld\n",query(l,r,1,n,1));
			while(!query(l,r,1,n,1))Update(l,r,x,1,n,1);
		}
	}
}