#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1LL<<55;
int n,m,len;
ll dp[60][20010],s[60][20010],pre[60][20010],suf[60][20010];
struct BIT {
	ll tr[80010];
	void init() {
		for (int i=1;i<=m*4;i++) tr[i]=-INF;
	}
	void add(int x,int l,int r,int root,ll delta) {
		if (l==r) { tr[root]=max(tr[root],delta); return; }
		int mid=(l+r)/2;
		if (x<=mid) add(x,l,mid,root*2,delta);
		else add(x,mid+1,r,root*2+1,delta);
		tr[root]=max(tr[root*2],tr[root*2+1]);
	}
	ll query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)/2; ll res=-INF;
		if (L<=mid) res=query(L,R,l,mid,root*2);
		if (mid<R) res=max(res,query(L,R,mid+1,r,root*2+1));
		return res;
	}
} T1[52],T2[52];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(len);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		read(s[i][j]);
		s[i][j]+=s[i][j-1];
	}
	for (int i=1;i<=n;i++) T1[i].init(),T2[i].init();
	for (int i=1;i<=1;i++) {
		for (int j=1;j+len-1<=m;j++) {
			dp[i][j]=s[i][j+len-1]-s[i][j-1];
			pre[i][j]=max(pre[i][j-1],dp[i][j]+s[i+1][j+len-1]-s[i+1][j-1]);
			T1[i+1].add(j,1,m,1,dp[i][j]-s[i+1][j-1]);
			T2[i+1].add(j,1,m,1,dp[i][j]+s[i+1][j+len-1]);
		}
		for (int j=m-len+1;j>=1;j--)
			suf[i][j]=max(suf[i][j+1],dp[i][j]+s[i+1][j+len-1]-s[i+1][j-1]);
	}
	int L,R;
	for (int i=2;i<=n;i++) {
		for (int j=1;j+len-1<=m;j++) {
			L=max(1,j-len+1);
			R=min(j+len-1,m);
			dp[i][j]=T1[i].query(L,j,1,m,1)+s[i][j-1];
			dp[i][j]=max(dp[i][j],T2[i].query(j,R,1,m,1)-s[i][j+len-1]);
			/*for (int k=L;k<=j;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][k]+s[i][j-1]-s[i][k-1]);
			for (int k=j+1;k<=R;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][k]+s[i][k+len-1]-s[i][j+len-1]);*/
			if (L>1) dp[i][j]=max(dp[i][j],pre[i-1][L-1]);
			if (R<m) dp[i][j]=max(dp[i][j],suf[i-1][R+1]);
			dp[i][j]+=s[i][j+len-1]-s[i][j-1];
			T1[i+1].add(j,1,m,1,dp[i][j]-s[i+1][j-1]);
			T2[i+1].add(j,1,m,1,dp[i][j]+s[i+1][j+len-1]);
			pre[i][j]=max(pre[i][j-1],dp[i][j]+s[i+1][j+len-1]-s[i+1][j-1]);		
		}
		for (int j=m-len+1;j>=1;j--)
			suf[i][j]=max(suf[i][j+1],dp[i][j]+s[i+1][j+len-1]-s[i+1][j-1]);
	}
	printf("%lld\n",pre[n][m-len+1]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/