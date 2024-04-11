#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int T,n,a[maxn],dy[maxn],d[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) {
			dy[i]=0;
			read(a[i]);
		}
		int x=1,tot=0;
		while (!dy[x]) {
			dy[x]=++tot;
			d[tot]=x;
			x=x-a[x];
		}
		printf("%d\n",tot-dy[x]+1);
		for (int i=dy[x];i<=tot;i++)
			printf("%d ",d[i]);
		printf("\n");
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