#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=3010;
int n,m;
set<int> g[maxn],g2[maxn];
vector<int> ans;
void dfs(int u) {
	while (!g2[u].empty()) {
		int v=*g2[u].begin();
		g2[u].erase(v),g2[v].erase(u);
		dfs(v);
	}
	ans.push_back(u);
}
bool check(int s) {
	int m=0;
	for (int i=1;i<=n;i++) g2[i]=g[i],m+=(int)g[i].size();
	ans.clear(); dfs(s);
	for (int i=1;i<=n;i++) g2[i]=g[i];
	for (int i=0;i+1<ans.size();i++) {
		int x=ans[i],y=ans[i+1];
		if (g2[x].count(y)!=1) return 0;
		g2[x].erase(y),g2[y].erase(x);
	}
	return m/2+1==(int)ans.size();
}
set<int> diff;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y;
	for (int i=1;i<=m;i++) read(x),read(y),g[x].insert(y),g[y].insert(x);
	for (int s=1;s<=n;s++) {
		set<int> Neb=g[s]; diff.clear();
		for (int x : Neb) {
			if ((int)g[x].size()%2==1) g[s].erase(x),g[x].erase(s),diff.insert(x);
		}
		if (check(s)) {
			ans.push_back(-1);
			for (int x : diff) ans.push_back(x),ans.push_back(s);
			printf("%d\n",(int)ans.size());
			for (int x : ans) printf("%d ",x); puts(""); return 0;
		}
		
		for (int x : Neb) {
			if (g[s].count(x)) {
				g[s].erase(x),g[x].erase(s),diff.insert(x);
			} else {
				g[s].insert(x),g[x].insert(s),diff.erase(x);
			}
			if (check(s)) {
				ans.push_back(-1);
				for (int x : diff) ans.push_back(x),ans.push_back(s);
				printf("%d\n",(int)ans.size());
				for (int x : ans) printf("%d ",x); puts(""); return 0;
			}
			if (g[s].count(x)) {
				g[s].erase(x),g[x].erase(s),diff.insert(x);
			} else {
				g[s].insert(x),g[x].insert(s),diff.erase(x);
			}
		}
		for (int x : diff) g[s].insert(x),g[x].insert(s);
	}
	puts("0");
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