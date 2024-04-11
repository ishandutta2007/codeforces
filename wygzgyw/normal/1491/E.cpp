#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=(2e5)+10;
int f[100],tot,dy[maxn];
int mk[maxn],tim,id;
int n,sz[maxn],fa[maxn];
void dfs(int u,int p,vector<int> *g) {
	sz[u]=1; fa[u]=p;
	for (int v : g[u]) {
		if (v==p) continue;
		dfs(v,u,g);
		sz[u]+=sz[v];
	}
}
int DFS(int u,int p,vector<pii> &E,vector<int> *g) {
	int x=++id,y;
	for (int v : g[u]) {
		if (v==p) continue;
		y=DFS(v,u,E,g);
		E.emplace_back(x,y);
	}
	return x;
}
bool solve(int n,vector<pii> &E) {
	int m=dy[n];
	//printf("OK in\n");
	if (m==0) return 0;
	if (n<=3) return 1;
	vector<int> g[n+5];
	for (pii A : E) g[A.first].push_back(A.second),g[A.second].push_back(A.first);
	int rt,p1,p2,tmp,t2;
	vector<pii> E1,E2;
	int TT=0;
	while (1) {
		rt=rand()%n+1;
		TT++;
		dfs(rt,0,g);
		p1=p2=-1;
		//printf("OK %d %d\n",n,rt);
		for (int i=1;i<=n;i++) {
			if (sz[i]==f[m-2]) p1=i;
			else if (sz[i]==f[m-1]) p2=i;
		}
		if (p1==-1&&p2==-1) return 0;
		if (TT==10) {
			if (p1!=-1) {
				id=0;
				DFS(p1,fa[p1],E1,g);
				tmp=id;
				id=0;
				DFS(fa[p1],p1,E2,g);
				t2=id;
				if (solve(tmp,E1)&&solve(t2,E2)) return 1;
			}
			if (p2!=-1) {
				id=0; E1.clear();
				DFS(p2,fa[p2],E1,g);
				tmp=id;
				id=0; E2.clear();
				DFS(fa[p2],p2,E2,g);
				t2=id;
				if (solve(tmp,E1)&&solve(t2,E2)) return 1;
			}
			return 0;
		}
		if (p1!=-1&&p2!=-1) continue;
		//printf("%d %d\n",p1,p2);
		if (p2!=-1) p1=p2;
		if (p1!=-1) {
			id=0;
			DFS(p1,fa[p1],E1,g);
			tmp=id;
			id=0;
			DFS(fa[p1],p1,E2,g);
			t2=id;
			if (solve(tmp,E1)&&solve(t2,E2)) return 1;
			return 0;
		}
	}
}
int main() {
	//freopen("2.txt","r",stdin);
	srand(time(0));
	f[0]=f[1]=1;
	for (int i=2;;i++) {
		f[i]=f[i-1]+f[i-2];
		if (f[i]>200000) break;
		tot=i;
	}
	for (int i=1;i<=tot;i++) dy[f[i]]=i;
	//printf("%d\n",f[tot]);
	read(n); int x,y;
	vector<pii> E;
	for (int i=1;i<n;i++) read(x),read(y),E.push_back(make_pair(x,y));
	if (solve(n,E)) puts("YES");
	else puts("NO");
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