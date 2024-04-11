#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n;
vector<int> g[maxn];
struct node { int a,b,c,d; };
vector<node> ans;
int dfs(int u,int p) {
	int nxt=u,cnt=0,now;
	for (int v : g[u]) if (v!=p) {
		now=dfs(v,u); if (now<0) continue;
		cnt++;
		if (cnt==1) nxt=now;
		else if (cnt==2) ans.push_back((node){u,p,nxt,now}),nxt=-1;
		else ans.push_back((node){v,u,v,now});
	}
	return nxt;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); ans.clear();
		for (int i=1;i<=n;i++) g[i].clear();
		int rt,x,y;
		for (int i=1;i<n;i++) read(x),read(y),g[y].push_back(x),g[x].push_back(y);
		for (int i=1;i<=n;i++) if ((int)g[i].size()==1) { rt=i; break; }
		int lst=dfs(rt,0);
		printf("%d\n",(int)ans.size());
		for (node A : ans) {
			printf("%d %d %d %d\n",A.a,A.b,A.c,lst); lst=A.d;
		}
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/