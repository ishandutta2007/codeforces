#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int T,n,m,p[maxn],q[maxn],tot;
struct node {
	int rt,sz;
	vector<int> leaves;
};
vector<int> tmp;
vector<node> res;
int in[maxn];
set<int> rem;
set<int> g[maxn];
vector<int> t[maxn];
int vis[maxn];
void dfs(int u) {
	rem.erase(u);
	int v=0;
	while (rem.size()) {
		set<int>::iterator it=rem.upper_bound(v);
		if (it==rem.end()) break;
		v=*it;
		if (g[u].find(v)!=g[u].end()) continue;
		t[u].emplace_back(v),t[v].emplace_back(u);
		//printf("add %d %d\n",u,v);
		dfs(v);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m); int x,y;
		for (int i=1;i<=n;i++) vis[i]=0,in[i]=-1,rem.insert(i),g[i].clear(),t[i].clear();
		res.clear();
		
		for (int i=1;i<=m;i++) {
			read(x),read(y);
			g[x].insert(y),g[y].insert(x);
		}
		
		while (rem.size()) {
			int u=*(rem.begin());
			dfs(u);
		}
		tot=n;
		for (int i=1;i<=n;i++) {
			if (t[i].empty()) {
				vis[i]=1;
				p[i]=q[i]=tot; tot--;
			}
		}
		
		for (int u=1;u<=n;u++) if (!vis[u]) {
			tmp.clear();
			for (int v : t[u]) {
				if (in[v]==-1) tmp.emplace_back(v);
			}
			//printf("HI %d\n",u);
			if (tmp.size()) {
				res.emplace_back((node){u,(int)tmp.size(),tmp});
				for (int v : tmp) in[v]=(int)res.size()-1,vis[v]=1;
				in[u]=(int)res.size()-1; vis[u]=1;
			} else {
				int v=t[u][0],w;
				//printf("%d %d\n",in[v],v);
				vis[u]=1;
				if (res[in[v]].sz>=2) {
					res[in[v]].sz--;
					res.emplace_back((node){u,1,{v}});
					in[v]=in[u]=(int)res.size()-1;
				} else {
					w=res[in[v]].rt;
					//printf("HI  %d\n",w);
					in[u]=in[v];
					res[in[v]]=(node){v,2,{u,w}};
					for (int w : t[v])
						if (!vis[w]) {
							vis[w]=1;
							in[w]=in[v];
							res[in[v]].leaves.push_back(w);
							res[in[v]].sz++;
						}
				}
			}
		}
		/*for (int i=0;i<res.size();i++) {
			printf("rt=%d : ",res[i].rt);
			for (int v : res[i].leaves) if (in[v]==i) printf("%d ",v);
			puts("");
		}*/
		tot=0;
		for (int i=0;i<res.size();i++) {
			int k=0;
			for (int v : res[i].leaves) if (in[v]==i) {
				k++;
				p[v]=k+1+tot,q[v]=k+tot;
			}
			p[res[i].rt]=1+tot,q[res[i].rt]=k+1+tot;
			tot+=k+1;
		}
		
		for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		for (int i=1;i<=n;i++) printf("%d ",q[i]); puts("");
		//printf("--------\n");
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