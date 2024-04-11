#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int l,r,n,tot;
struct node { int x,y,z; } ans[10010];
int main() {
	//freopen("1.txt","r",stdin);
	read(l),read(r);
	n=23;
	puts("YES");
	for (int i=2;i<=n;i++) ans[++tot]=(node){1,i,l};
	for (int i=2;i<=n-2;i++) {
		for (int j=i+1;j<=n-1;j++) ans[++tot]=(node){i,j,1<<(i-2)};
	}
	for (int i=2;i<=n-1;i++)
		if ((r-l)>>(i-2)&1) ans[++tot]=(node){i,n,((r-l)&((1<<30)-(1<<i-1)))+1};
	printf("%d %d\n",n,tot);
	for (int i=1;i<=tot;i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
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