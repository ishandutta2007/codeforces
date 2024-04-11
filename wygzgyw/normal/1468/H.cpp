#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,m,k,a[maxn];
bool flag;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k),read(m);
		for (int i=1;i<=m;i++) read(a[i]);
		if ((n-m)%(k-1)!=0) puts("NO");
		else {
			flag=0;
			for (int i=1;i<=m;i++)
				if (a[i]-i>=k/2&&n-a[i]-m+i>=k/2) { flag=1; break; }
			if (flag) puts("YES");
			else puts("NO");
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