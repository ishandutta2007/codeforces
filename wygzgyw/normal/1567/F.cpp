// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair

int n,m;
char s[510][510];
int fx[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int col[510][510];
pair<int,int> bk[500*500+5];
int num[510][510],tot; vector<int> g[500*500+5];
void add(int x,int y) { g[x].push_back(y),g[y].push_back(x); }
void dfs(int x) {
	for (int y : g[x]) if (!col[bk[y].first][bk[y].second]) {
		col[bk[y].first][bk[y].second]=5-col[bk[x].first][bk[x].second];
		dfs(y);
	}
}
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) num[i][j]=++tot,bk[tot]=MP(i,j);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='X') {
		vector<pair<int,int> > A;
		for (int k=0;k<4;k++) {
			int x=i+fx[k][0],y=j+fx[k][1];
			if (s[x][y]=='.') A.push_back(MP(x,y));
		}
		if ((int)A.size()%2!=0) { puts("NO"); return 0; }
		for (int k=0;k<A.size();k+=2) add(num[A[k].first][A[k].second],num[A[k+1].first][A[k+1].second]);
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
		if (!col[i][j]&&s[i][j]=='.') {
			col[i][j]=1;
			dfs(num[i][j]);
		}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='X') {
		col[i][j]=0;
		for (int k=0;k<4;k++) {
			int x=i+fx[k][0],y=j+fx[k][1];
			if (s[x][y]=='.') col[i][j]+=col[x][y];
		}
	}
	puts("YES");
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) printf("%d ",col[i][j]);
		puts("");
	}
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