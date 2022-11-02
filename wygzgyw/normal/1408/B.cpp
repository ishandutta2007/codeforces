#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,k,m;
int cnt,a[10010];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k);
		for (int i=1;i<=n;i++) read(a[i]);
		bool flag=1;
		for (int i=1;i<=n;i++) if (a[i]!=a[1]) { flag=0; break; }
		if (flag) { printf("1\n"); continue; }
		
		if (k==1) printf("-1\n");
		else {
			cnt=0;
			for (int i=1;i<n;i++) if (a[i]!=a[i+1]) cnt++;
			if (cnt%(k-1)==0) printf("%d\n",cnt/(k-1));
			else printf("%d\n",cnt/(k-1)+1);
		}
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