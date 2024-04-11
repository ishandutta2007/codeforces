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
const int maxn=(5e5)+10;
const int INF=1e9;
int T,n;
ll a[maxn],s[maxn],lsh[maxn];
int dp[maxn],N,mx[maxn];
namespace T1 {
	int tr[maxn];
	void add(int x,int delta) {
		for (;x<=N;x+=x&(-x)) tr[x]=max(tr[x],delta);
	}
	int query(int x) {
		int res=-INF;
		for (;x;x-=x&(-x)) res=max(res,tr[x]);
		return res;
	}
	void clear() { for (int i=1;i<=N;i++) tr[i]=-INF; }
};
namespace T2 {
	int tr[maxn];
	void add(int x,int delta) {
		for (;x;x-=x&(-x)) tr[x]=max(tr[x],delta);
	}
	int query(int x) {
		int res=-INF;
		for (;x<=N;x+=x&(-x)) res=max(res,tr[x]);
		return res;
	}
	void clear() { for (int i=1;i<=N;i++) tr[i]=-INF; }
};
void chkmax(int &x,int y) { if (x<y) x=y; }
int main() {
	read(T); while (T--) {
		read(n);
		N=0;
		lsh[++N]=0;
		for (int i=1;i<=n;i++) read(a[i]),s[i]=a[i]+s[i-1],lsh[++N]=s[i];
		sort(lsh+1,lsh+N+1);
		N=unique(lsh+1,lsh+N+1)-lsh-1;
		int rk=lower_bound(lsh+1,lsh+N+1,0)-lsh;
		T1::clear(),T2::clear();
		T1::add(rk,0);
		T2::add(rk,0);
		for (int i=1;i<=N;i++) mx[i]=-INF;
		mx[rk]=0;
		for (int i=1;i<=n;i++) {
			rk=lower_bound(lsh+1,lsh+N+1,s[i])-lsh;
			dp[i]=-INF;
			chkmax(dp[i],mx[rk]);
			chkmax(dp[i],T1::query(rk-1)+i);
			chkmax(dp[i],T2::query(rk+1)-i);
			chkmax(mx[rk],dp[i]);
			T1::add(rk,dp[i]-i);
			T2::add(rk,dp[i]+i);
		}
		printf("%d\n",dp[n]);
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