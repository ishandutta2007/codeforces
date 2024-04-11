#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,k,x[110],y[110];
void solve() {
	for (int i=1;i<=n;i++) {
		int flag=1;
		for (int j=1;j<=n;j++)
			if (abs(x[i]-x[j])+abs(y[i]-y[j])>k) { flag=0; break; }
		if (flag) { puts("1"); return; }
	}
	puts("-1");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
		solve();
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/