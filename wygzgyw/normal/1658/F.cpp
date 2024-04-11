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
const int maxn=(4e5)+10;
int T,n,m,sum,pre[maxn];
char s[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		scanf("%s",s+1);
		sum=0;
		for (int i=n+1;i<=n*2;i++) s[i]=s[i-n];
		for (int i=1;i<=n;i++) sum+=s[i]-'0';
		if (((ll)sum*m)%n!=0) { puts("-1"); continue; }
		sum=((ll)sum*m)/n;
		for (int i=1;i<=n*2;i++) {
			pre[i]=pre[i-1]+s[i]-'0';
			if (i>=m&&pre[i]-pre[i-m]==sum) {
				if (i<=n) printf("1\n%d %d\n",i-m+1,i);
				else printf("2\n%d %d\n%d %d\n",1,i-n,i-m+1,n);
				break;
			}
		}
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