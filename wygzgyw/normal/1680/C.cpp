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
const int maxn=(2e5)+10;
int T,n;
char s[maxn];
int a[maxn],b[maxn];
int all;
bool check(int mid) {
	for (int i=1;i<=n;i++) {
		int x=upper_bound(a+1,a+n+1,a[i-1]+mid)-a-1;
		int y=lower_bound(b+1,b+n+1,all+b[i-1]-mid)-b;
		if (x>=y) return 1;
	}
	return 0;
}
int main() {
	read(T);
	while (T--) {
		scanf("%s",s+1),n=strlen(s+1);
		for (int i=1;i<=n;i++) {
			a[i]=a[i-1],b[i]=b[i-1];
			if (s[i]=='0') a[i]++; else b[i]++;
		}
		all=b[n];
		int l=0,r=all,res=all,mid;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)) res=min(res,mid),r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",res);
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