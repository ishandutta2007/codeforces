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
const int INF=1e9;
int T,n;
int rem[maxn];
int main() {
		int now=0,d=2,ans;
		for (int i=2;;i++) {
			now+=d;
			//printf("i=%d,d=%d\n",i,d);
			rem[i]=now;
			ans=i;
			if (now>=INF) break;
			if (i%3!=0) d+=2;
		}
	read(T);
	while (T--) {
		read(n);
		int x=lower_bound(rem+1,rem+ans+1,n)-rem;
		printf("%d\n",x);
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