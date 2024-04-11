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
const int mod=998244353;
const int maxn=(1e5)+10;
int T,n,a[maxn];
int cnt,b[maxn];

int main() {
	read(T);
	while (T--) {
		read(n);
		cnt=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]==0) cnt++;
		}
		int hd=1,tl=cnt,flag=0;
		while (n-hd+1>1) {
			if (tl==n) { flag=1; break; }
			if (tl-hd+1>0) {
				a[tl]=0;
				for (int i=tl+1;i<=n;i++) b[i]=a[i]-a[i-1];
				sort(b+tl+1,b+n+1);
				hd++;
				for (int i=tl+1;i<=n;i++) a[i]=b[i];
				while (tl<n&&a[tl+1]==0) tl++;
			} else {
				for (int i=hd,j=1;i<n;i++,j++) b[j]=a[i+1]-a[i];
				int len=n-hd+1;
				sort(b+1,b+len);
				for (int i=1;i<len;i++) a[i]=b[i];
				n=len-1;
				hd=1,tl=0;
				while (tl<n&&a[tl+1]==0) tl++;
			}
			//for (int i=hd;i<=n;i++) printf("%d ",a[i]); puts("");
		}
		if (flag) puts("0");
		else printf("%d\n",a[n]);
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