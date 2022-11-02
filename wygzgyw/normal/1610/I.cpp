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
const int maxn=(3e5)+10;
int n,ans,cnt,sg[maxn];
vector<int> g[maxn];
int fa[maxn];
bool mk[maxn];
void dfs(int u,int p) {
	fa[u]=p; for (int &v : g[u]) if (v!=p) dfs(v,u),sg[u]^=sg[v]+1;
}
void print() {
	if (ans^(cnt&1)) putchar('1'); else putchar('2');
}
int main() {
	read(n);
	int x,y; for (int i=1;i<n;i++) read(x),read(y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0); ans=sg[1]; mk[1]=1;
	print();
	for (int i=2;i<=n;i++) {
		if (!mk[i]) {
			x=i;
			while (!mk[x]) {
				ans^=sg[x]+1;
				for (int &y : g[x]) if (y!=fa[x]) ans^=sg[y]+1;
				cnt++; mk[x]=1; x=fa[x];
			}
		}
		print();
	} puts("");
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