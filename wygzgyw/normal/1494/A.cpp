#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n;
char s[60];
void solve() {
	for (int t=0;t<8;t++) {
		int flag=1,now=0;
		for (int i=1;i<=n;i++) {
			if (t>>(s[i]-'A')&1) now++;
			else now--;
			if (now<0) { flag=0; break; }
		}
		if (!flag||now!=0) continue;
		puts("YES"); return;
	}
	puts("NO");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1); n=strlen(s+1);
		solve();
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