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
const int maxn=(1e5)+10;
const int up=1,dwn=0;
int T,n,a,b,d[maxn];
int p[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(a),read(b);
		int A=a,B=b;
		if (a+b>n-2||abs(a-b)>1) { puts("-1"); continue; }
		for (int i=1;i<=n;i++) d[i]=-1,p[i]=0;
		int flag;
		if (a>b) flag=1; else flag=0;
		for (int i=2;i<=n;i++) {
			if (a==0&&b==0) break;
			if (i%2==1-flag) {
				d[i]=up; a--;
			} else d[i]=dwn,b--;
		}
		//for (int i=1;i<=n;i++) printf("%d ",d[i]); puts("");
		int L=1,R=n,lst=0;
		for (int i=1;i<=n;i++) if (d[i]==up) p[i]=R,R--,lst=up; else if (d[i]==dwn) p[i]=L,L++,lst=dwn;
		if (lst==dwn) {
			for (int i=1;i<=n;i++) {
				if (!p[i]) p[i]=L,L++;
			}
		} else {
			for (int i=1;i<=n;i++) if (!p[i]) p[i]=R,R--;
		}
		for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		for (int i=2;i<n;i++) {
			if (p[i]>p[i-1]&&p[i]>p[i+1]) A--;
			if (p[i]<p[i-1]&&p[i]<p[i+1]) B--;
		}
		assert(!A&&!B);
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