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
const int maxn=(1e5)+10;
int T;
int n,N;
ll a[maxn],s[maxn],X,lsh[maxn];
int b[maxn],dp[maxn],pre[maxn];
int lst[maxn],st[maxn][20];
int lg[maxn];
int query(int l,int r) {
	int j=lg[r-l+1];
	return max(st[l][j],st[r-(1<<j)+1][j]);
}
namespace BIT {
	int tr[maxn];
	void init() { for (int i=1;i<=n+1;i++) tr[i]=-1e9; }
	void add(int x,int delta) {
		x++; x=n-x+2;
		for (;x<=n+1;x+=x&(-x)) tr[x]=max(tr[x],delta);
	}
	int query(int x) {
		x++; x=n-x+2;
		int res=-1e9; for (;x;x-=x&(-x)) res=max(res,tr[x]); return res;
	}
};
int main() {
//	freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),dp[i]=0;
		for (int i=2;i<=n+1;i++) lg[i]=lg[i>>1]+1;
		read(X); N=0;
		for (int i=1;i<=n;i++) a[i]-=X,s[i]=s[i-1]+a[i],lsh[++N]=s[i]; lsh[++N]=0;
		sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
		//for (int i=1;i<=n;i++) printf("%lld ",s[i]); puts("");
		for (int i=0;i<=n;i++) b[i]=lower_bound(lsh+1,lsh+N+1,s[i])-lsh;
		for (int i=0;i<=n;i++) st[i][0]=b[i];
		for (int i=1;i<=19;i++) for (int j=0;j+(1<<i)-1<=n;j++) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		for (int i=1;i<=n;i++) {
			int l=0,r=i-2,mid,res=-1;
			while (l<=r) {
				mid=(l+r)>>1;
				if (query(mid,i-2)>b[i]) res=mid,l=mid+1;
				else r=mid-1;
			}
			lst[i]=min(i,res+2);
			if (lst[i]<=i-1) lst[i]=max(lst[i],lst[i-1]);
		//	printf("lst[%d]=%d\n",i,lst[i]);
		}
		BIT::init();
		BIT::add(0,0);
		for (int i=1;i<=n;i++) {
			if (i==1) dp[1]=1;
			else {
				dp[i]=pre[i-2]+1;
				dp[i]=max(dp[i],BIT::query(lst[i]-1)+i);
			}
			pre[i]=max(pre[i-1],dp[i]);
			int tmp=pre[i-1];
			BIT::add(i,tmp-i);
			//printf("dp[%d]=%d\n",i,dp[i]);
		}
		printf("%d\n",pre[n]);
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