// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
const ll INF=1e18;
int n,m,a[maxn];
struct node {
	int l,r;
	friend bool operator == (node A,node B) { return A.l==B.l&&A.r==B.r; }
	friend bool operator < (node A,node B) { if (A.l!=B.l) return A.l<B.l; return A.r>B.r; }
} d[maxn],e[maxn];
int M,T;
ll dp[maxn][2],ans;
void chkmin(ll &x,ll y) { if (x>y) x=y; }
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=m;i++) {
			int l,r; read(l),read(r);
			int x=lower_bound(a+1,a+n+1,l)-a;
			if (x<=n&&x>=1&&a[x]<=r) { i--; m--; continue; }
			d[i]=(node){l,r};
		}
		sort(d+1,d+m+1),m=unique(d+1,d+m+1)-d-1;
		if (m==0) { puts("0"); continue; }
		int mn=2e9; M=0;
		for (int i=m;i>=1;i--) {
			if (mn<=d[i].r); else e[++M]=d[i];
			mn=min(mn,d[i].r);
		}
		m=M; for (int i=1;i<=M;i++) d[i]=e[i];
		sort(d+1,d+m+1);
	//	for (int i=1;i<=m;i++) printf("%d %d\n",d[i].l,d[i].r);
		for (int i=0;i<=n;i++) dp[i][0]=dp[i][1]=INF; ans=INF;
		for (int i=1;i<=n;i++) {
			e[i].l=lower_bound(d+1,d+m+1,(node){a[i],0})-d;
		}
		e[0].l=1;
		for (int i=0;i<n;i++) e[i].r=e[i+1].l-1;
		e[n].r=m;
		if (e[0].l<=e[0].r) {
			dp[1][0]=a[1]-d[1].r;
			dp[1][1]=2*dp[1][0];
		} else dp[1][0]=dp[1][1]=0;
	//	for (int i=0;i<=n;i++) printf("[%d,%d]\n",e[i].l,e[i].r);
		for (int i=2;i<=n;i++) {
			int x=e[i-1].l,y=e[i-1].r;
			if (x<=y) {
				for (int k1=0;k1<=1;k1++)
				for (int k2=0;k2<=1;k2++)
				for (int j=x;j<y;j++) {
					int t1=(!k1?2:1),t2=(!k2?1:2);
					//assert(d[j].l>=a[i-1]&&a[i]>=d[j+1].r);
					chkmin(dp[i][k2],(ll)(d[j].l-a[i-1])*t1+(ll)(a[i]-d[j+1].r)*t2+dp[i-1][k1]);
				}
				for (int k2=0;k2<=1;k2++) {
					int t2=(!k2?1:2);
					//assert(a[i]>=d[x].r);
					chkmin(dp[i][k2],(ll)(a[i]-d[x].r)*t2+min(dp[i-1][0],dp[i-1][1]));
				}
				for (int k1=0;k1<=1;k1++) {
					int t1=(!k1?2:1);
					//assert(d[y].l>=a[i-1]);
					chkmin(dp[i][1],(ll)(d[y].l-a[i-1])*t1+dp[i-1][k1]);
				}
			} else {
				dp[i][0]=dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
			}
			//printf("> %lld %lld\n",dp[i][0],dp[i][1]);
		}
		int x=e[n].l;
		if (x<=m) {
			for (int k1=0;k1<=1;k1++) {
				int t1=(!k1?2:1);
				chkmin(ans,dp[n][k1]+(ll)t1*(d[m].l-a[n]));
			}
		} else ans=min(dp[n][0],dp[n][1]);
		printf("%lld\n",ans);
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