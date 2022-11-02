#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e10;
const int maxn=(2e5)+10;
int n,s1,s2;
ll a[maxn],ans,dep[maxn];
int b[maxn],c[maxn];
vector<int> g[maxn];
struct node {
	int x,y;
	friend node operator + (node t1,node t2) {
		return (node){t1.x+t2.x,t1.y+t2.y};
	}
};
node dfs(int u,int p) {
	node res=(node){0,0};
	if (b[u]!=c[u]) {
		if (b[u]) res.x++;
		else res.y++;
	}
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (v==p) continue;
		dep[v]=min(dep[u],a[u]);
		res=res+dfs(v,u);
	}
	if (a[u]<dep[u]) {
		int tmp=min(res.x,res.y);
		ans+=tmp*2*a[u];
		res.x-=tmp,res.y-=tmp;
	}
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]),read(b[i]),read(c[i]);
		s1+=b[i],s2+=c[i];
	}
	if (s1!=s2) { printf("-1\n"); return 0; }
	int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dep[1]=INF;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/