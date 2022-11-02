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
const int maxn=2000*2000+10;
int n,tot;
int head[maxn],to[maxn*4],nxt[maxn*4],TOT;
bool w[maxn*4];
char s[2010][2010];
int num[2010][2010],d[maxn];
int lst; bool vis[maxn];
void add(int x,int y,int z) {
	TOT++; nxt[TOT]=head[x]; head[x]=TOT; to[TOT]=y; w[TOT]=z;
}
void merge(int x) {
	add(lst,x,1);
	add(x,lst,1);
	lst=x;
}
void link(int x,int y) { add(x,y,0); add(y,x,0); }
void No() { puts("NONE"); exit(0); }
void dfs(int x) {
	vis[x]=1;
	for (int i=head[x],y;i;i=nxt[i]) {
		y=to[i];
		if (!w[i]) {
			if (d[y]&&d[x]!=d[y]) No();
			if (!vis[y]) d[y]=d[x],dfs(y);
		} else {
			if (d[y]&&d[x]==d[y]) No();
			if (!vis[y]) d[y]=3-d[x],dfs(y);
		}
	}
}
int main() {
	read(n); if (n&1) No();
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (int j=1;j<=n;j++) num[i][j]=++tot,d[tot]=(s[i][j]=='.'?0:s[i][j]=='S'?1:2);
	}
	for (int i=1;i<=n;i+=2) {
		int x=1,y=i; lst=num[1][i];
		link(lst,num[1][i+1]);
		while (y>1&&x<n) {
			x++,y--;
			merge(num[x][y]);
		}
		link(num[x][y],num[x+1][y]);
		lst=num[x+1][y]; x++;
		while (x<n&&y<n) {
			x++,y++;
			merge(num[x][y]);
		}
		link(num[x][y],num[x][y+1]);
		lst=num[x][y+1]; y++;
		while (x>1&&y<n) {
			x--,y++;
			merge(num[x][y]);
		}
		lst=num[x-1][y]; x--;
		while (x>1&&y>1) {
			x--,y--;
			merge(num[x][y]);
		}
	}
	for (int i=1;i<=tot;i++) if (!vis[i]&&d[i]) dfs(i);
	for (int i=1;i<=tot;i++) if (!d[i]) { puts("MULTIPLE"); return 0; }
	puts("UNIQUE");
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) putchar(d[num[i][j]]==1?'S':'G');
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