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
int n,q,ans;
char s[maxn];
int check(int i) { return (s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'); }
int main() {
	read(n),read(q); scanf("%s",s+1); for (int i=1;i<n-1;i++) ans+=check(i);
	int pos; char t[10];
	while (q--) {
		read(pos); scanf("%s",t+1);
		for (int i=max(1,pos-2);i<=min(n-2,pos);i++) ans-=check(i);
		s[pos]=t[1];
		for (int i=max(1,pos-2);i<=min(n-2,pos);i++) ans+=check(i);
		printf("%d\n",ans);
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