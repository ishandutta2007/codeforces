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
#define ll long long
struct node{int l,r,idx;}q[N];
bool cmp(const node &a,const node &b){return a.r==b.r?a.l<b.l:a.r<b.r;}
int n,Q;

ll s[N<<2],tag[N<<2],ans[N],t[N];
int sta[N],top,a[N];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void Update(int L,int R,int v,int l,int r,int rt)
{
	if(L>R)return ;s[rt]+=(ll)(min(R,r)-max(l,L)+1)*v;
	if(L<=l&&r<=R){tag[rt]+=v;return ;}int m=(l+r)>>1;
	if(L<=m)Update(L,R,v,lson);if(m<R)Update(L,R,v,rson);
}
ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return s[rt];int m=(l+r)>>1;ll ret=tag[rt]*(min(r,R)-max(l,L)+1);
	if(L<=m)ret+=query(L,R,lson);if(m<R)ret+=query(L,R,rson);return ret;
}
void print(int now,int l,int r,int rt)
{
	if(l==r){printf("%d ",s[rt]+now);return ;}int m=(l+r)>>1;
	print(now+tag[rt],lson);print(now+tag[rt],rson);
}

int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=Q;i++)q[i].idx=i,scanf("%d",&q[i].l);
	for(int i=1;i<=Q;i++)scanf("%d",&q[i].r);sort(q+1,q+Q+1,cmp);
	for(int i=1,j=1;i<=n;i++)
	{
		while(top&&a[sta[top]]<a[i])
		{
			int p=sta[top-1];
			Update(p+1,sta[top]-1,1,1,n,1);
			Update(sta[top],sta[top],i-sta[top],1,n,1);top--;
		}sta[++top]=i,t[top]=t[top-1]+sta[top-1];
		while(i==q[j].r)
		{
			int p=lower_bound(sta+1,sta+top+1,q[j].l)-sta-1;
			// printf("%d %d %d %lld\n",top,p,(top-p)*i-(t[top]-t[p+1]+q[j].l-1),query(q[j].l,i,1,n,1));
			ans[q[j].idx]=(ll)(top-p)*i-(t[top]-t[p+1]+q[j].l-1)+query(q[j].l,i,1,n,1),j++;
		}
		// if(i==8||i==9)print(0,1,n,1),puts("");
	}
	for(int i=1;i<=Q;i++)printf("%lld ",ans[i]);puts("");
}