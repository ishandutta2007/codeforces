#include <iostream>
using namespace std;
int dp[35005],lst[35005],l[35005],qwq[35005];
struct stree
{
	int now,l,r,add,mn;
}t[132000];
const int X=2e9;
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r,t[now].add=0;
	if(l==r)
	{
		t[now].mn=X;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].mn=min(t[now*2].mn,t[now*2+1].mn);
}
inline void give(int now,int k)
{
	t[now].add+=k,t[now].mn+=k;
}
inline void pushdown(int now)
{
	if(t[now].l!=t[now].r)
		give(now*2,t[now].add),give(now*2+1,t[now].add),t[now].add=0;
}
inline void change(int now,int l,int r,int k)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r)
	{
		give(now,k);
		return ;
	}
	if(t[now*2].r>=r) change(now*2,l,r,k);
	else if(t[now*2+1].l<=l) change(now*2+1,l,r,k);
	else change(now*2,l,t[now*2].r,k),change(now*2+1,t[now*2+1].l,r,k);
	t[now].mn=min(t[now*2].mn,t[now*2+1].mn);
}
inline int query()
{
	return t[1].mn;
}
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		l[i]=qwq[x];
		qwq[x]=i;
	}
	for(int i=1;i<=n;i++)
		lst[i]=lst[i-1]+(!!l[i])*(i-l[i]);
	for(int i=2;i<=k;i++)
	{
		build(1,0,n);
		change(1,0,0,-X);
		for(int j=1;j<=n;j++)
		{
			if(l[j]) change(1,0,l[j]-1,j-l[j]);
			dp[j]=query();
			change(1,j,j,lst[j]-X);
		}
		swap(dp,lst);
	}
	cout << lst[n];
	return 0;
}