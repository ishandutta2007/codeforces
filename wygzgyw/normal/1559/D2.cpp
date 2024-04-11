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
const int maxn=(1e5)+10;
int n,m[2],sz[2][maxn];
int fa[2][maxn],cnt[2][maxn];
map<int,vector<int> > g[2][maxn];
set<int> ok[2],alive[2];
vector<pair<int,int> > ans;
int find(int t,int x) {
	if (fa[t][x]==x) return x;
	return fa[t][x]=find(t,fa[t][x]);
}
void insert(int t,int x,int y,int z) {
	//printf("happy insert %d %d %d %d\n",t,x,y,z);
	if (!g[t][x].count(y)) cnt[t][x]++;
	if (cnt[t][x]==2) ok[t].insert(x);//,printf("HIHI %d %d\n",t,x);
	g[t][x][y].push_back(z);
}
void init(int t,int x,int y) {
	if (g[t][x].count(y)==0) return;
	//printf("init %d %d %d\n",t,x,y);
	cnt[t][x]--;
	if (cnt[t][x]==1) {
		ok[t].erase(x);
		//printf(">   BYE %d %d\n",t,x);
	}
	g[t][x].erase(g[t][x].find(y));
}
void Clear(int t,int x) {
	//printf("Clear %d %d\n",t,x);
	if (ok[t].count(x)) ok[t].erase(x);
	cnt[t][x]=0; g[t][x].clear();
}
#define xyr pair<int,vector<int> >
void merge(int t,int x,int y) {
	if (sz[t][x]>sz[t][y]) swap(x,y);
	//printf("MERGE %d %d %d\n",t,x,y);
	alive[t].erase(x); sz[t][y]+=sz[t][x]; fa[t][x]=y;
	for (xyr A : g[t][x]) {
		for (int a : A.second) {
			int aa=find(t^1,a);
			insert(t^1,aa,y,a);
			init(t^1,aa,x);
			insert(t,y,aa,a);
		}
	}
	Clear(t,x);
	//printf("MERGE DONE %d %d %d\n",t,x,y);
}
void solve(int x,int y) {
	ans.push_back(MP(x,y));
	//printf("link %d %d\n",x,y);
	merge(0,find(0,x),find(0,y));
	merge(1,find(1,x),find(1,y));
}
int main() {
	read(n); int x,y; read(m[0]),read(m[1]);
	for (int i=0;i<=1;i++) {
		for (int j=1;j<=n;j++) fa[i][j]=j,sz[i][j]=1;
		while (m[i]--) {
			read(x),read(y),x=find(i,x),y=find(i,y);
			sz[i][y]+=sz[i][x];
			fa[i][x]=y;
		}
	}
	for (int t=0;t<=1;t++) {
		for (int j=1;j<=n;j++) insert(t,find(t,j),find(t^1,j),j),alive[t].insert(find(t,j));
	}
	while (sz[0][find(0,1)]!=n&&sz[1][find(1,1)]!=n) {
		if (!(int)ok[0].size()&&!(int)ok[1].size()) {
			for (int i=1;i<=n;i++) if (find(0,1)!=find(0,i)) solve(1,i);
			break;
		}
		for (int t=0;t<=1;t++) {
			if ((int)ok[t].size()==0) continue;
			int a=*ok[t].begin(); alive[t].erase(a);
			//printf("> %d %d\n",t,a);
			int b=*alive[t].begin(); alive[t].insert(a);
			//printf("> %d %d %d\n",t,a,b);
			for (xyr B : g[t][b]) {
				y=B.first;
				break;
			}
			for (xyr A : g[t][a]) if (A.first!=y) { x=A.first; break; }
			//printf("HI %d %d\n",x,y);
			x=g[t][a][x].back(),y=g[t][b][y].back();
			//printf("HI %d %d\n",x,y);
			solve(x,y);
			break;
		}
	}
	printf("%d\n",(int)ans.size());
	for (pair<int,int> &A : ans) printf("%d %d\n",A.first,A.second);
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