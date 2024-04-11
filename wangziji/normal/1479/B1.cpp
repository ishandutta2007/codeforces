#include <iostream>
using namespace std;
int nxt[100005],qwq[100005],a[100005],dp[100005];
int now1,now2,ans;
struct stree
{
	int l,r,mn,lazy;
}t[300005];
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
		return ;
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].mn=min(t[now*2+1].mn,t[now*2].mn); 
}
inline void give(int now,int x)
{
	t[now].mn+=x,t[now].lazy+=x;
}
inline void pushdown(int now)
{
	if(t[now].l!=t[now].r)
		give(now*2,t[now].lazy),give(now*2+1,t[now].lazy),t[now].lazy=0;
}
inline void change(int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r)
	{
		give(now,-1);
		return ;
	}
	pushdown(now);
	if(t[now*2].r>=r) change(now*2,l,r);
	else if(t[now*2+1].l<=l) change(now*2+1,l,r);
	else change(now*2,l,t[now*2].r),change(now*2+1,t[now*2+1].l,r);
	t[now].mn=min(t[now*2+1].mn,t[now*2].mn); 
}
inline int query(int now,int l,int r)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r) return t[now].mn;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else return min(query(now*2,l,t[now*2].r),query(now*2+1,t[now*2+1].l,r));
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	build(1,0,n);
	for(int i=1;i<=n;i++)
	{
		int mx=max(-query(1,0,a[i]-1),(a[i]!=n)?-query(1,a[i]+1,n):0);
		if(a[i]!=a[i-1])change(1,0,n);
		while(-query(1,a[i-1],a[i-1])<mx+1) change(1,a[i-1],a[i-1]);
	}
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,-query(1,i,i));
	cout << ans;
	return 0;
}