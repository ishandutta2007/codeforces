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
int T,n,fa[maxn];
vector<int> g[maxn];
int dep[maxn],id[maxn],sz[maxn];
void dfs(int u,int p) {
	fa[u]=p; dep[u]=dep[p]+1;
	sort(g[u].begin(),g[u].end());
	if (p) g[u].erase(lower_bound(g[u].begin(),g[u].end(),p));
	for (int &v : g[u]) dfs(v,u);
}
bool cmp(int x,int y) { return dep[x]>dep[y]; }
bool rm[maxn];

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); int x,y;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++) {
			read(x),read(y);
			g[x].push_back(y),g[y].push_back(x);
		}
		dfs(1,0);
		for (int i=1;i<=n;i++) id[i]=i,rm[i]=0;
		sort(id+1,id+n+1,cmp);
		for (int i=1;i<n;i++) {
			x=id[i]; sz[x]=1;
			int flag=1;
			for (int &y : g[x]) if (!rm[y]) {
				flag&=sz[y]==1; sz[x]+=sz[y];
			}
			if (flag&&sz[x]>1) {
				rm[x]=1;
			}
		}
		int cnt=0,flag=0;
		for (int i=2;i<=n;i++) if (rm[i]) cnt++;//,printf("rm %d\n",i);
		for (int i=2;i<=n;i++) if (fa[i]==1&&!rm[i]) {
			assert(sz[i]==1);
			flag=1;
		}
		printf("%d\n",n-cnt*2-flag);
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