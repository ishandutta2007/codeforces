#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,ans[maxn][maxn];
struct node { int x,id; } d[maxn];
bool cmp(node a,node b) { return a.x>b.x; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(d[i].x),d[i].id=i;
	sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=d[i].x;j++)
		ans[(i+j)%(n+1)][d[i].id]=1;
	printf("%d\n",n+1);
	for (int i=0;i<=n;i++) {
		for (int j=1;j<=n;j++) printf("%c",ans[i][j]+'0');
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