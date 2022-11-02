#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,k,mx,ans,x;
int main() {
	read(n); read(k);
	for (int i=1;i<=k+1;i++) {
		printf("? ");
		for (int j=1;j<=k+1;j++)
			if (j!=i) printf("%d ",j);
		printf("\n");
		fflush(stdout);
		read(x); read(x);
		if (x>mx) mx=x,ans=1;
		else if (x==mx) ans++;
	}
	printf("! %d\n",ans);
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