#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(3e5)+10;
int T,p[maxn],n;
int lft[maxn],rgt[maxn];
int st[20][maxn],lg[maxn];
char ans[maxn];
namespace Seg {
	int tr[maxn*4];
	void build(int l,int r,int root) {
		tr[root]=INF;
		if (l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	}
	void pushup(int root) { tr[root]=min(tr[root<<1],tr[root<<1|1]); }
	void add(int x,int l,int r,int root,int delta) {
		if (l==r) { tr[root]=min(tr[root],delta); return; }
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta);
		else add(x,mid+1,r,root<<1|1,delta);
		pushup(root);
	}
	int query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1,res=INF;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=min(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
};
int dp[maxn],from[maxn];
int mx[maxn];
int query(int l,int r) {
	if (l>r) return -INF;
	int j=lg[r-l+1];
	return max(st[j][l],st[j][r-(1<<j)+1]);
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=2;i<maxn;i++) lg[i]=lg[i>>1]+1;
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) {
			read(p[i]);
			lft[i]=max(1,i-p[i]);
			rgt[i]=min(n,i+p[i]);
			st[0][i]=rgt[i]; dp[i]=-INF; from[i]=-1;
		}
		for (int j=1;j<=19;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		Seg::build(0,n,1);
		Seg::add(0,0,n,1,0);
		int lst;
		for (int i=1;i<=n;i++) {
			lst=Seg::query(lft[i]-1,n,0,n,1);
			if (lst!=INF) {
				from[i]=lst;
				dp[i]=max(query(lst+1,i-1),dp[lst]);
				if (p[i]) dp[i]=max(dp[i],i-1);
			}
			if (dp[i-1]>=i&&max(dp[i-1],rgt[i])>dp[i]) {
				dp[i]=max(dp[i-1],rgt[i]);
				from[i]=-1;
			}
			if (dp[i-1]>dp[i]) dp[i]=dp[i-1],from[i]=-1;
			if (dp[i]!=-INF) Seg::add(dp[i],0,n,1,i);
			//printf("%d\n",dp[i]);
		}
		if (dp[n]!=n) { puts("NO"); continue; }
		puts("YES");
		for (int i=1;i<=n;i++) ans[i]='R'; ans[n+1]=0;
		int pos=n;
		while (pos) {
			if (from[pos]==-1) pos--;
			else {
				ans[pos]='L';
				pos=from[pos];
			}
		}
		printf("%s\n",ans+1);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/