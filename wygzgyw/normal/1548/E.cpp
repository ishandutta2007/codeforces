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
const int INF=1e9;
const int maxn=(2e5)+10;
int n,m,X; ll ans;
int a[maxn],b[maxn],na[maxn],nb[maxn];
int s[maxn],tot,L[maxn],R[maxn];
int st[maxn][20],lg[maxn];
int query(int l,int r) {
	int j=lg[r-l+1];
	return max(st[l][j],st[r-(1<<j)+1][j]);
}
void solve(int n,int *a,int *na) {
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;i++) st[i][0]=a[i];
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	tot=0;
	for (int i=1;i<=n;i++) {
		while (tot&&a[s[tot]]>a[i]) tot--;
		L[i]=s[tot]; s[++tot]=i;
	}
	tot=0;
	for (int i=n;i>=1;i--) {
		while (tot&&a[s[tot]]>=a[i]) tot--;
		R[i]=s[tot]; s[++tot]=i;
	}
	for (int i=1;i<=n;i++) {
		na[i]=INF;
		if (L[i]) na[i]=query(L[i],i);
		if (R[i]) na[i]=min(na[i],query(i,R[i]));
	}
}
int id[maxn],id2[maxn];
bool cmp(int x,int y) { return a[x]<a[y]; }
bool cmp2(int x,int y) { return nb[x]<nb[y]; }
namespace Seg {
	int tr[maxn];
	void add(int x) { for (;x<maxn;x+=x&(-x)) tr[x]++; }
	int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
	int query(int l,int r) { return query(r)-query(l-1); }
};
int main() {
	read(n),read(m),read(X);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=m;i++) read(b[i]);
	solve(n,a,na);
	solve(m,b,nb);
	//for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (a[i]+b[j]<=X&&na[i]+b[j]>X&&a[i]+nb[j]>X) ans++;
	for (int i=1;i<=n;i++) id[i]=i; sort(id+1,id+n+1,cmp);
	for (int i=1;i<=m;i++) id2[i]=i; sort(id2+1,id2+m+1,cmp2);
	int pos=m+1;
	for (int I=1;I<=n;I++) {
		int i=id[I];
		while (pos>1&&nb[id2[pos-1]]>X-a[i]) {
			pos--;
			Seg::add(b[id2[pos]]);
		}
		int L=max(1,X-na[i]+1),R=min(200000,X-a[i]);
		if (L<=R) ans+=Seg::query(L,R);
	}
	
	printf("%lld\n",ans);
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