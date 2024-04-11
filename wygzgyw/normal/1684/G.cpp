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
const int maxn=1010;
int n,m;
int a[maxn];
int mat[maxn],vis[maxn];
vector<int> g[maxn];
bool dfs(int x) {
	if (vis[x]) return 0;
	vis[x]=1;
	for (int &y : g[x]) {
		if (mat[y]==-1||dfs(mat[y])) {
			mat[y]=x; return 1;
		}
	}
	return 0;
}
int main() {
	read(n),read(m);
	vector<int> l,r;
	for (int i=1;i<=n;i++) {
		read(a[i]);
		if (a[i]>m/3) l.push_back(a[i]);
		else r.push_back(a[i]);
	}
	int t1=(int)l.size(),t2=(int)r.size();
	for (int i=0;i<t1;i++) for (int j=0;j<t2;j++)
		if ((long long)l[i]*2+r[j]<=m&&l[i]%r[j]==0) g[i].push_back(j);
	for (int i=0;i<t2;i++) mat[i]=-1;
	int cnt=0;
	for (int i=0;i<t1;i++) {
		memset(vis,0,sizeof(vis));
		if (dfs(i)) cnt++;
	}
	if (cnt!=t1) { puts("-1"); return 0; }
	vector<pair<int,int> > ans;
	for (int i=0;i<t2;i++) if (mat[i]==-1) ans.push_back(MP(3*r[i],2*r[i])); else ans.push_back(MP(l[mat[i]]*2+r[i],l[mat[i]]+r[i]));
	printf("%d\n",(int)ans.size());
	for (auto [x,y] : ans) printf("%d %d\n",x,y);
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