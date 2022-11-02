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
const int maxn=(2e5)+10;
int T,n;
vector<pair<int,int> > g[maxn];
int X[maxn],Y[maxn];
int mk[maxn],deg[maxn],flag;
void No() { if (!flag) puts("NO"); flag=1; }
int q[maxn],hd,tl,in[maxn];
vector<int> h[maxn];
void dfs(int u,int p,int f) {
	deg[u]=(int)g[u].size();
	int c0=0,c1=0;
	for (auto [v,id] : g[u]) if (v!=p) {
		dfs(v,u,id);
		if (mk[id]) c1++; else c0++;
	}
	if (u==1) {
		if (deg[u]%2==0) {
			if (c0!=c1) No();
		} else if (c1!=c0+1) No();
		return;
	}
	if (deg[u]%2==0) {
		if (c0==c1+1) mk[f]=1;
		else if (c1==c0+1) mk[f]=0;
		else No();
	} else {
		if (c1==c0+2) mk[f]=0;
		else if (c1==c0) mk[f]=1;
		else No();
	}
}
int main() {
	read(T);
	while (T--) {
		read(n);
		int x,y; for (int i=1;i<=n;i++) g[i].clear(),h[i].clear(),in[i]=0;
		for (int i=1;i<n;i++) {
			read(x),read(y);
			g[x].push_back(MP(y,i));
			g[y].push_back(MP(x,i));
			X[i]=x,Y[i]=y;
		}
		flag=0;
		dfs(1,0,0);
		if (flag) continue;
		puts("YES");
		for (int i=1;i<=n;i++) {
			vector<int> M,V[2];
			for (auto [v,id] : g[i]) V[mk[id]].push_back(id);
			if (deg[i]%2==0) {
				for (int j=0;j<V[0].size();j++) M.push_back(V[0][j]),M.push_back(V[1][j]);
			} else {
				for (int j=0;j<V[0].size();j++) M.push_back(V[1][j]),M.push_back(V[0][j]); M.push_back(V[1].back());
			}
			for (int j=0;j+1<M.size();j++) {
				h[M[j]].push_back(M[j+1]),in[M[j+1]]++;
			}
		}
		hd=1,tl=0;
		for (int i=1;i<n;i++) if (!in[i]) q[++tl]=i;
		while (hd<=tl) {
			int x=q[hd]; hd++;
			for (int &y : h[x]) {
				in[y]--; if (!in[y]) q[++tl]=y;
			}
		}
		for (int i=1;i<n;i++) printf("%d %d\n",X[q[i]],Y[q[i]]);
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