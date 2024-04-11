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
const int maxn=2010;
int n,S;
int query(int x) {
	printf("? %d\n",x); fflush(stdout); scanf("%d",&x); return x;
}
int main() {
	scanf("%d",&n);
	int l=1,r=2e8,mid,res;
	while (l<=r) {
		mid=(l+r)>>1;
		if (query(mid)==1) res=mid,r=mid-1; else l=mid+1;
	}
	S=res;
	int ans=S;
	for (int i=1;i<=n;i++) {
		int h=query(S/i);
		if (h) ans=min(ans,h*(S/i));
	}
	printf("! %d\n",ans); fflush(stdout);
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