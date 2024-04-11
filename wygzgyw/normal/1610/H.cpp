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
int n,m,bg[maxn],ed[maxn],fa[maxn][20],dep[maxn];
int tot; vector<int> g[maxn];
void dfs(int u,int p) {
	bg[u]=++tot,dep[u]=dep[p]+1;
	for (int &v : g[u]) {
		dfs(v,u);
	}
	ed[u]=tot;
}
int ans,flag,chk[maxn];
bool in(int x,int y) {
	return bg[y]<=bg[x]&&ed[x]<=ed[y];
}
namespace BIT {
	int tr[maxn];
	void add(int x) { for (;x<=n;x+=x&(-x)) tr[x]++; }
	int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
	int query(int l,int r) { if (l>r) return 0; return query(r)-query(l-1); }
};
set<pair<int,int> > s;
int rem[maxn],X[maxn],Y[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m); int x,y,z;
	for (int i=2;i<=n;i++) {
		read(fa[i][0]),g[fa[i][0]].push_back(i);
	}
	dfs(1,0);
	for (int i=1;i<=19;i++) for (int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		if (dep[x]>dep[y]) swap(x,y);
		if (in(y,x)) {
			if (dep[y]==dep[x]+1) { puts("-1"); return 0; }
			z=y;
			for (int j=19;j>=0;j--) if (dep[fa[z][j]]>dep[x]) z=fa[z][j];
			s.insert(MP(-dep[z],i)); rem[i]=z;
		} else chk[i]=1; X[i]=x,Y[i]=y;
	}
	while (!s.empty()) {
		int i=(*s.begin()).second; s.erase(s.begin());
		x=X[i],y=Y[i],z=rem[i];
		if (BIT::query(bg[z],ed[z])-BIT::query(bg[y],ed[y])>0) continue;
		BIT::add(bg[z]); ans++;
		//printf("add %d\n",z);
	}
	flag=1;
	for (int i=1;i<=m;i++) if (chk[i]) {
		x=X[i],y=Y[i];
		if (BIT::query(bg[x],ed[x])+BIT::query(bg[y],ed[y])==ans) flag=0;
	}
	if (!flag) ans++;
	printf("%d\n",ans);
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