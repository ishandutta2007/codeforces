#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
int n,m;
int d[210][210],col[210];
void dfs(int u) {
	for (int i=1;i<=n;i++) if (d[u][i]<INF&&i!=u) {
		if (col[i]) {
			if (col[i]==col[u]) { puts("NO"); exit(0); }
		} else {
			col[i]=(col[u]^1);
			dfs(i);
		}
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); int x,y,z;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]=INF;
	for (int i=1;i<=n;i++) d[i][i]=0;
	for (int i=1;i<=m;i++) {
		read(x),read(y),read(z);
		d[x][y]=1;
		if (!z) d[y][x]=1;
		else d[y][x]=-1;
	}
	col[1]=2; dfs(1);
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int s=-1,mx=-1,tmp;
	for (int i=1;i<=n;i++) {
		if (d[i][i]<0) { puts("NO"); return 0; }
		tmp=0; for (int j=1;j<=n;j++) tmp=max(tmp,d[i][j]);
		if (tmp>mx) mx=tmp,s=i;
	}
	puts("YES");
	printf("%d\n",mx);
	for (int i=1;i<=n;i++) printf("%d ",d[s][i]); puts("");
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