#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#pragma GCC optimize 2
using namespace std;
const int N=2e4+9;
struct stree
{
	int l,r,lazy,sum;
}t[N<<2];
int dp[20005];//dp[i][j]ij 
inline void pushdown(int now)
{
	int lazy=t[now].lazy;if(!lazy) return ;
	if(t[now].l!=t[now].r) t[now*2].lazy+=lazy,t[now*2+1].lazy+=lazy;
	t[now].sum+=lazy;t[now].lazy=0;
}
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r,t[now].lazy=0;
	if(l==r)
	{
		t[now].sum=dp[l];
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].sum=max(t[now*2].sum,t[now*2+1].sum);
}
inline void change(int now,int l,int r,int d)
{
	if(l>r) return ;
	pushdown(now);
	if(t[now].l==l&&t[now].r==r)
	{
		t[now].lazy+=d;
		return ;
	}
	pushdown(now);
	if(t[now*2].r>=r) change(now*2,l,r,d);
	else if(t[now*2+1].l<=l) change(now*2+1,l,r,d);
	else change(now*2,l,t[now*2].r,d),change(now*2+1,t[now*2+1].l,r,d);
	pushdown(now);
	if(t[now].l!=t[now].r) pushdown(now*2),pushdown(now*2+1),t[now].sum=max(t[now*2].sum,t[now*2+1].sum);
}
inline int query(int now,int l,int r)
{
	pushdown(now);
	if(l>r) return 0;
	if(t[now].l==l&&t[now].r==r) return t[now].sum;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else return max(query(now*2,l,t[now*2].r),query(now*2+1,t[now*2+1].l,r));
}
int qzh[55][20005],a[55][20005],cf[20005];
int main() {
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			qzh[i][j]=qzh[i][j-1]+a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		{
			for(int j=1;j<=k;j++)
				dp[j]-=qzh[i][k]-qzh[i][j-1];
		}
//		for(int j=1;j<=m-k+1;j++) cout << dp[j] << " ";
//		puts("");
		build(1,1,m);
		memset(dp,0,sizeof dp);
		for(int j=1;j<=m-k+1;j++)
		{
//			cout << query(1,1,m) << "\n";
			dp[j]=query(1,1,m)-qzh[i][j-1]-qzh[i+1][j-1]+qzh[i][j+k-1]+qzh[i+1][j+k-1];
			if(i!=1) change(1,max(1,j-k+1),min(m,j),a[i][j]),change(1,max(1,j+1),min(m,j+k),-a[i][j+k]);
			ans=max(ans,dp[j]);
//			cout << dp[j] << " ";
		}
//		puts(""); 
	}
	cout << ans;
	return 0;
}
/*
3 5 2
15 5 2 10 12
5 3 12 2 14
1 7 6 4 11
*/