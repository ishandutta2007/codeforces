#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005];
struct stree
{
	int l,r,mx,mn;
}t[500005];
inline void upd(int now)
{
	t[now].mx=max(t[now*2].mx,t[now*2+1].mx);
	t[now].mn=min(t[now*2].mn,t[now*2+1].mn);
}
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
		t[now].mx=t[now].mn=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	upd(now);
}
inline int qx(int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r) return t[now].mx;
	if(t[now*2].r>=r) return qx(now*2,l,r);
	if(t[now*2+1].l<=l) return qx(now*2+1,l,r);
	return max(qx(now*2,l,t[now*2].r),qx(now*2+1,t[now*2+1].l,r)); 
}
inline int qn(int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r) return t[now].mn;
	if(t[now*2].r>=r) return qn(now*2,l,r);
	if(t[now*2+1].l<=l) return qn(now*2+1,l,r);
	return min(qn(now*2,l,t[now*2].r),qn(now*2+1,t[now*2+1].l,r)); 
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a[i]-=x,a[i]+=a[i-1];
	}
	build(1,1,n);
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		int mx=qx(1,l,r),mn=qn(1,l,r);
		if(a[r]!=a[l-1]||mx>a[l-1])
		{
			cout << "-1\n";
		}
		else cout << -mn+a[l-1] << "\n";
	}
	return 0;
}