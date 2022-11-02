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
const int maxn=55;
int T,n;
int a[maxn],b[maxn],tot;
int main() {
	read(T); while (T--) {
		read(n);
		int sum=0;
		int c0=0; vector<int> V1,V2;
		int s1=0,s2=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			sum+=a[i];
			if (a[i]==0) c0++;
			else if (a[i]>0) V1.push_back(a[i]),s1+=a[i];
			else V2.push_back(-a[i]),s2-=a[i];
		}
		if (sum==0) { puts("NO"); continue; }
		tot=0;
		if (s1>s2) {
			for (int &x : V1) b[++tot]=x;
			for (int &x : V2) b[++tot]=-x;
		} else {
			for (int &x : V2) b[++tot]=-x;
			for (int &x : V1) b[++tot]=x;
		}
		for (int i=1;i<=c0;i++) b[++tot]=0;
		puts("YES");
		for (int i=1;i<=tot;i++) printf("%d ",b[i]); puts("");
		
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