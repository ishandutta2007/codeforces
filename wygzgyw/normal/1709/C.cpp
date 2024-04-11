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
int T,d[maxn];
char s[maxn];
char t[maxn];
bool chk(int n) {
	int sum=0;
	for (int i=1;i<=n;i++) {
		if (t[i]=='(') sum++; else sum--;
		if (sum<0) return 0;
	}
	return 1;
}
int main() {
	read(T);
	while (T--) {
		scanf("%s",s+1);
		int n=strlen(s+1),c0=0,c1=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='(') c0++; else if (s[i]==')') c1++;
		}
		int tot=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='?') d[++tot]=i;
		}
		int a=n/2-c0,b=n/2-c1;
		if (!a||!b) { puts("YES"); continue; }
		for (int i=1;i<=n;i++) t[i]=s[i];
		for (int i=1;i<=tot;i++) {
			if (i<=a) t[d[i]]='(';
			else t[d[i]]=')';
		}
		swap(t[d[a]],t[d[a+1]]);
		if (chk(n)) puts("NO");
		else puts("YES");
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