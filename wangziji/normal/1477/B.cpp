#include <iostream>
#include <cstdio>
using namespace std;
pair <int,int> op[200005];
char a[200005],b[200005];
struct stree
{
	int l,r,sum,ling,yi;
}t[600005];
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r,t[now].sum=t[now].ling=t[now].yi=0;
	if(l==r)
	{
		t[now].sum=b[l]-'0';
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].sum=t[now*2].sum+t[now*2+1].sum;
}
inline void give0(int now)
{
	t[now].yi=0,t[now].ling|=1,t[now].sum=0;
}
inline void give1(int now)
{
	t[now].ling=0,t[now].yi|=1,t[now].sum=t[now].r-t[now].l+1;
}
inline void pushdown(int now)
{
	if(t[now].l!=t[now].r)
	{
		if(t[now].ling) t[now].ling=0,give0(now*2),give0(now*2+1);
		if(t[now].yi) t[now].yi=0,give1(now*2),give1(now*2+1);
	}
}
inline void change(int now,int l,int r,int k)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r)
	{
		if(k==0) give0(now);
		else give1(now);
		return ;
	}
	if(t[now*2].r>=r) change(now*2,l,r,k);
	else if(t[now*2+1].l<=l) change(now*2+1,l,r,k);
	else change(now*2,l,t[now*2].r,k),change(now*2+1,t[now*2+1].l,r,k);
	t[now].sum=t[now*2].sum+t[now*2+1].sum; 
}
inline int query(int now,int l,int r)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r) return t[now].sum;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else return query(now*2,l,t[now*2].r)+query(now*2+1,t[now*2+1].l,r);
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,q;
		scanf("%d%d%s%s",&n,&q,a+1,b+1);
		build(1,1,n);
		for(int i=1;i<=q;i++)
			scanf("%d%d",&op[i].first,&op[i].second);
		int flag=1;
		for(int i=q;i>=1;i--)
		{
			int l=op[i].first,r=op[i].second;
			int t=query(1,l,r);
			if(t*2==(r-l+1)) flag=0;
			else if(t*2<(r-l+1)) change(1,l,r,0);
			else change(1,l,r,1);
		}
		for(int i=1;i<=n;i++) if(a[i]!=query(1,i,i)+'0') flag=0;
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}