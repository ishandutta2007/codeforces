#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,ans[110];
int a[110],b[110],c[110];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]);
		for (int i=1;i<=n;i++) read(c[i]);
		ans[1]=a[1];
		for (int i=2;i<n;i++) {
			if (a[i]==ans[i-1]) ans[i]=b[i]; else ans[i]=a[i];
		}
		if (a[n]==ans[1]||a[n]==ans[n-1]) {
			if (b[n]==ans[1]||b[n]==ans[n-1]) ans[n]=c[n];
			else ans[n]=b[n];
		} else ans[n]=a[n];
		for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/