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
const int maxn=610;
const int maxm=300010;
int n,a[maxm];
namespace xyr {
const int maxm=1000000;
int n,tot,head[maxn],id[610][610];
int nxt[maxm],to[maxm],ans;
void Add(int x,int y) {
    tot++; nxt[tot]=head[x];
    head[x]=tot; to[tot]=y;
}
void add(int x,int y,int z) {
	if (id[x][y]) return;
	id[x][y]=id[y][x]=z;
    Add(x,y); Add(y,x);
}
int match[maxn],pre[maxn],vis[maxn],fa[maxn];
queue<int> q;
int find(int x) {
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int mk[maxn],cnt;
int lca(int x,int y) {
    cnt++;
    while (1) {
        if (x) {
            x=find(x);
            if (mk[x]==cnt) return x;
            mk[x]=cnt; x=pre[match[x]];
        }
        swap(x,y);
    }
}
void blossom(int x,int y,int z) {
    while (find(x)!=z) {
        pre[x]=y; y=match[x];
        if (vis[y]==2) vis[y]=1,q.push(y);
        if (find(x)==x) fa[x]=z;
        if (find(y)==y) fa[y]=z;
        x=pre[y];
    }
}
int dfs(int s) {
    for (int i=1;i<=n;i++)
        vis[i]=pre[i]=0,fa[i]=i;
    q=queue<int>();
    q.push(s); vis[s]=1;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=head[u],v;i;i=nxt[i]) {
            v=to[i];
            if (find(u)==find(v)||vis[v]==2) continue;
            if (!vis[v]) {
                vis[v]=2; pre[v]=u;
                if (!match[v]) {
                    for (int x=v,lst;x;x=lst)
                        lst=match[pre[x]],match[x]=pre[x],match[pre[x]]=x;
                    return 1;
                }
                vis[match[v]]=1;
                q.push(match[v]);
            } else {
                int z=lca(u,v);
                blossom(u,v,z);
                blossom(v,u,z);
            }
        }
    }
    return 0;
}
void solve() {
	for (int i=n;i>=1;i--)
        if (!match[i]) ans+=dfs(i);
}
};
bool ban[610]; int mx,used[maxm];
vector<pair<int,int> > V,V2;
namespace BF {
vector<int> g[610]; int tim[610]; queue<int> q;
void link(int x,int y) {
	g[x].push_back(y),g[y].push_back(x);
}
void solve() {
	for (int i=1;i<=mx;i++) tim[i]=-1;
	for (int i=1;i<=mx;i++) if (ban[i]) tim[i]=0,q.push(i);
	while (!q.empty()) { int x=q.front(); q.pop(); for (int &y : g[x]) if (tim[y]==-1) tim[y]=tim[x]+1,q.push(y); }
}
};
int dir[maxm],bel[maxn]; bool MK[maxm];
namespace Forest {
bool oncyc[610],vis[610]; int fa[610],from[610];
vector<pair<int,int>> g[610];
void add(int x,int y,int z) {
	g[x].push_back(MP(y,z)),g[y].push_back(MP(x,z));
}
int X,Y,Z; vector<int> V[610];
int D[610],tot,S,dis[610];
void dfs(int x,int p,int w) {
	vis[x]=1; fa[x]=p; from[x]=w; V[S].push_back(x);
	dis[x]=dis[p]+1;
	for (auto [y,z] : g[x]) {
		if (z==from[x]) continue;
		if (vis[y]) {
			if (dis[x]>dis[y]) Y=x,X=y,Z=z;
		} else dfs(y,x,z);
	}
}
int VIS[610];
void DFS(int x,int f) {
	VIS[x]=1;
	for (auto [y,z] : g[x]) if (!oncyc[y]&&z!=f&&!VIS[y]) {
		DFS(y,z); dir[z]=y;
	}
} int TREE[610];
void solve() {
	for (int i=1;i<=mx;i++) if (!vis[i]) {
		X=Y=0; S=i;
		dfs(i,0,-1);
		if (X) {
			tot=0;
			dir[Z]=X;
			while (1) {
				D[++tot]=Y;
				if (Y==X) break;
				dir[from[Y]]=Y;
				Y=fa[Y];
			}
			for (int j=1;j<=tot;j++) oncyc[D[j]]=1;
			for (int j=1;j<=tot;j++) DFS(D[j],0);
		} else {
			TREE[i]=1;
			for (int &x : V[i]) {
				bel[x]=i;
			}
		}
	}
	tot=0;
}
int XYR[610];
void insert(int x) { XYR[bel[x]]=x; }
void insert(int x,int y) { insert(x),insert(y); }
void solve_again() {
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=mx;i++) if (bel[i]==i&&TREE[i]) {
		if (XYR[i]) {
			S=i; V[i].clear();
			dfs(XYR[i],0,-1);
		} else XYR[i]=i;
		for (int &x : V[i]) if (x!=XYR[i]) dir[from[x]]=x;
	}
}
};
int now,R[maxm];
int GETNXT() {
	while (used[now]) now++; used[now]=1; return now;
}
int main() {
	read(n); int F1=1,F2=1; for (int i=1;i<=n;i++) read(a[i]),R[i]=a[i],mx=max(mx,a[i]),used[a[i]]=1,F1&=(a[i]==0),F2&=(a[i]!=0);
	if (F1) { for (int i=0;i<n;i++) printf("%d ",i/2+1); puts(""); return 0; }
	if (F2) { for (int i=1;i<=n;i++) printf("%d ",a[i]); puts(""); return 0; }
	now=1;
	for (int l=1,r;l<=n;l=r+1) if (!a[l]) {
		r=l; while (r<n&&!a[r+1]) r++;
		int x=a[l-1],y=a[r+1],len=r-l+1;
		if (l==1) {
			if (len&1) {
				for (int i=1;i<r;i+=2) a[i]=a[i+1]=GETNXT(); a[r]=a[r+1];
			} else {
				for (int i=1;i<=r;i+=2) a[i]=a[i+1]=GETNXT();
			}
		} else if (r==n) {
			if (len&1) {
				for (int i=l+1;i<=n;i+=2) a[i]=a[i+1]=GETNXT(); a[l]=a[l-1];
			} else {
				for (int i=l;i<=n;i+=2) a[i]=a[i+1]=GETNXT();
			}
		} else {
			assert(x&&y);
			if (x==y) {
				if (len&1) { a[l]=a[l-1]; for (int i=l+1;i<=r;i+=2) a[i]=a[i+1]=GETNXT(); }
				else { for (int i=l;i<=r;i+=2) a[i]=a[i+1]=GETNXT(); }
			} else {
				V.push_back(MP(l,r));
			}
		}
	} else r=l;
	for (int i=1;i<n;i++) if (a[i]&&a[i+1]&&a[i]==a[i+1]&&a[i]<=mx) ban[a[i]]=1;
	for (pair<int,int> &A : V) if ((A.second-A.first+1)%2==1) BF::link(a[A.first-1],a[A.second+1]);
	BF::solve();
	for (int i=1;i<=mx;i++) ban[i]=(BF::tim[i]!=-1);
	for (auto [l,r] : V) {
		int x=a[l-1],y=a[r+1],len=r-l+1;
		if (ban[y]&&(!ban[x]||BF::tim[y]<=BF::tim[x])) {
			if (len&1) { for (int i=l+1;i<=r;i+=2) a[i]=a[i+1]=GETNXT(); a[l]=a[l-1]; }
			else { for (int i=l;i<=r;i+=2) a[i]=a[i+1]=GETNXT(); }
		} else if (ban[x]&&(!ban[y]||BF::tim[y]>=BF::tim[x])) {
			if (len&1) { for (int i=l;i<r;i+=2) a[i]=a[i+1]=GETNXT(); a[r]=a[r+1]; }
			else { for (int i=l;i<=r;i+=2) a[i]=a[i+1]=GETNXT(); }
		} else V2.push_back(MP(l,r));
	}
	for (int i=0;i<V2.size();i++) {
		int l=V2[i].first,r=V2[i].second,x=a[l-1],y=a[r+1],len=r-l+1;
		if (len&1) Forest::add(x,y,i);
	}
	Forest::solve();
	xyr::n=mx;
	for (int i=0;i<V2.size();i++) {
		int l=V2[i].first,r=V2[i].second,x=a[l-1],y=a[r+1],len=r-l+1;
		if (len&1^1) xyr::add(bel[x],bel[y],i+1);
	}
	xyr::solve();
	for (int i=1;i<=mx;i++) if (xyr::match[i]&&xyr::match[i]<i) {
		int z=xyr::id[i][xyr::match[i]]-1;
		MK[z]=1; int x=a[V2[z].first-1],y=a[V2[z].second+1];
		Forest::insert(x,y);
	}
	Forest::solve_again();
	for (int i=0;i<V2.size();i++) {
		int l=V2[i].first,r=V2[i].second,x=a[l-1],y=a[r+1],len=r-l+1;
		if (MK[i]) {
			a[l]=a[l-1],a[r]=a[r+1];
			for (int j=l+1;j<r;j+=2) a[j]=a[j+1]=GETNXT();
		} else if (dir[i]) {
			if (dir[i]==x) { for (int j=l+1;j<=r;j+=2) a[j]=a[j+1]=GETNXT(); a[l]=a[l-1]; }
			else { for (int j=l;j<r;j+=2) a[j]=a[j+1]=GETNXT(); a[r]=a[r+1]; }
		} else if (len&1) {
			for (int j=l;j<r;j+=2) a[j]=a[j+1]=GETNXT(); a[r]=GETNXT();
		} else {
			for (int j=l;j<=r;j+=2) a[j]=a[j+1]=GETNXT();
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
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