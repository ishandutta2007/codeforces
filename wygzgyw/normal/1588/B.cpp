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
int T,n;
int p[10000];
ll all;
ll query(int l,int r) {
	if (l>r) return 0;
	printf("? %d %d\n",l,r); fflush(stdout);
	ll x; scanf("%lld",&x); return x;
//	ll ans=0; for (int i=l;i<=r;i++) for (int j=i+1;j<=r;j++) if (p[i]>p[j]) ans++; return ans;
}
ll C(ll x) { return x*(x-1)/2; }
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		int i,j,k;
		//scanf("%d %d %d",&i,&j,&k); for (int i=1;i<=n;i++) p[i]=i; reverse(p+i,p+j),reverse(p+j,p+k+1);
		all=query(1,n);
		int l=1,r=n,mid,res=0;
		while (l<=r) {
			mid=(l+r)>>1;
			if (query(mid,n)==all) res=mid,l=mid+1; else r=mid-1;
		}
		i=res;
		j=i+all-query(i+1,n)+1;
		all-=C(j-i);
		l=1,r=n;
		while (l<=r) {
			mid=(l+r)>>1;
			if (C(mid)>=all) res=mid,r=mid-1; else l=mid+1;
		}
		k=j+res-1;
		printf("! %d %d %d\n",i,j,k);
		fflush(stdout);
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