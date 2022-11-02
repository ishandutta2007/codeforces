#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
int p[510],ans[510][510];
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(p[i]);
	for (int i=1;i<=n;i++) {
		int x=i,y=i;
		for (int j=1;j<=p[i];j++) {
			ans[x][y]=p[i];
			if (j==p[i]) break;
			if (!ans[x][y-1]&&y>1) y--; else x++;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++) printf("%d ",ans[i][j]);
		puts("");
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