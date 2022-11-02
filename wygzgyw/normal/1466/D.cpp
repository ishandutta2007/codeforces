#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T,n,tot,deg[maxn];
ll ans[maxn],a[maxn],w[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int x,y;
		for (int i=1;i<=n;i++) read(w[i]),deg[i]=ans[i]=0;
		for (int i=1;i<n;i++) {
			read(x),read(y);
			deg[x]++,deg[y]++;
			ans[n-1]+=w[x]+w[y];
		}
		tot=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<deg[i];j++) a[++tot]=w[i];
		sort(a+1,a+tot+1);
		int pos=0;
		for (int i=n-2;i>=1;i--) {
			pos++;
			ans[i]=ans[i+1]-a[pos];
		}
		for (int i=1;i<n;i++) printf("%lld ",ans[i]);
		printf("\n");
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