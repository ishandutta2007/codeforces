#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 100005
#define M 300005
#define inf 0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
char buf[1000000],*p1,*p2;
int rd()
{
	int y;scanf("%d",&y);return y;
	register int x=0;register char c=nc();
	while(c<'0'||c>'9')c=nc();
	while(c>='0'&&c<='9')x=((x+(x<<2))<<1)+(c^48),c=nc();
	return x;
}
struct QaQ{int l,r,idx;}q[M];
bool cmp(const QaQ &a,const QaQ &b){return a.r==b.r?a.l<b.l:a.r<b.r;}
int mn[N<<2],n,Q,a[N],ans[M];vector<int>v[N<<2];
vector<int>::iterator it;
void build(int l,int r,int rt)
{
	mn[rt]=inf;if(l==r){v[rt].push_back(a[l]);return;}int m=(l+r)>>1;
	build(lson);build(rson);
	for(int i=l;i<=r;i++)v[rt].push_back(a[i]);sort(v[rt].begin(),v[rt].end());
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return mn[rt];int ret=inf,m=(l+r)>>1;
	if(L<=m)ret=query(L,R,lson);if(m<R)ret=min(ret,query(L,R,rson));return ret;
}
void Update(int p,int x,int &d,int l,int r,int rt)
{
	if(l==r){mn[rt]=min(mn[rt],abs(x-a[l]));d=min(mn[rt],d);return ;}
	int m=(l+r)>>1;it=lower_bound(v[rt].begin(),v[rt].end(),x);
	if((it==v[rt].end()||(*it-x>=d))&&(it==v[rt].begin()||(x-*--it>=d)))
		{d=min(d,mn[rt]);return ;}
	if(m<p)Update(p,x,d,rson);Update(p,x,d,lson);mn[rt]=min(mn[rt<<1|1],mn[rt<<1]);
}
int main()
{
	// freopen("Theater.in","r",stdin);
	// freopen("Theater.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();build(1,n,1);
	Q=rd();
	for(int i=1;i<=Q;i++)q[i]=(QaQ){rd(),rd(),i};
	sort(q+1,q+Q+1,cmp);
	for(int i=1,j=1;i<=Q;i++)
	{
		while(j<q[i].r){int tmp=inf;Update(j,a[j+1],tmp,1,n,1);j++;}
		ans[q[i].idx]=query(q[i].l,q[i].r,1,n,1);
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}