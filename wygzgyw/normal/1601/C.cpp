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
const int maxn=(1e6)+10;
int T,n,m,a[maxn],b[maxn];
pair<int,int> d[maxn*2];
int rk[maxn*2],c[maxn],tot;
ll ans;
int tr[maxn*2],N;
void init() { for (int i=1;i<=N;i++) tr[i]=0; }
void add(int x) {
	for (;x;x-=x&(-x)) tr[x]++;
}
int query(int x) {
	int res=0; for (;x<=N;x+=x&(-x)) res+=tr[x]; return res;
}
int pos[maxn];
void solve(int l,int r,int L,int R) {
	if (l>r) return;
	int mid=(l+r)>>1,sum=0,mn=1e9;
	for (int i=L;i<=R;i++) {
		if (mn>sum) mn=sum,pos[mid]=i;
		sum+=(a[i]>b[mid])-(a[i]<b[mid]);
	}
	solve(l,mid-1,L,pos[mid]);
	solve(mid+1,r,pos[mid],R);
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=m;i++) read(b[i]); sort(b+1,b+m+1);
		solve(1,m,1,n+1);
		tot=0;
		for (int i=1,j=1;i<=n+1;i++) {
			while (j<=m&&pos[j]<=i) c[++tot]=b[j],j++;
			if (i<=n) c[++tot]=a[i];
		}
		for (int i=1;i<=tot;i++) d[i]=MP(c[i],i);
		sort(d+1,d+tot+1); N=0;
		for (int i=1;i<=tot;i++) {
			if (d[i].first!=d[i-1].first||i==1) N++;
			rk[d[i].second]=N;
		}
		init(); ans=0;
		for (int i=1;i<=tot;i++) ans+=query(rk[i]+1),add(rk[i]);
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