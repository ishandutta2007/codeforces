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
int n,cnt[210],p[210],a[210],b[210];
int query() {
	printf("? "); for (int i=1;i<=n;i++) printf("%d ",a[i]); puts(""); fflush(stdout);
	int x; scanf("%d",&x); return x;
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++) cnt[a[i]+p[i]]++;
	for (int i=1;i<=n;i++) if (cnt[a[i]+p[i]]>1) return i;
	return 0;
}
int main() {
	scanf("%d",&n);
	//for (int i=1;i<=n;i++) read(p[i]);
	for (int x=-(n-1);x<n;x++) {
		if (x==0) continue;
		if (x<0) {
			a[n]=1-x;
			for (int i=1;i<n;i++) a[i]=1;
			int k=query(); if (k) b[k]=x;
		} else {
			a[n]=1;
			for (int i=1;i<n;i++) a[i]=1+x;
			int k=query(); if (k) b[k]=x;
		}
	}
	//for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
	int mx=0;
	for (int i=1;i<=n;i++) mx=max(mx,b[i]);
	p[n]=mx+1;
	for (int i=1;i<n;i++) p[i]=p[n]-b[i];
	printf("! ");
	for (int i=1;i<=n;i++) printf("%d ",p[i]); puts(""); fflush(stdout);
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