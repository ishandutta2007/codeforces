#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n;
int a[maxn],flag;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); flag=1;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]!=a[1]) flag=0;
		}
		if (flag) printf("%d\n",n);
		else printf("1\n");
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