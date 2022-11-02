#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
const double INF=1e18;
const double eps=1e-8;
int n,m,head[maxn],nxt[maxn*2],to[maxn*2],tot;
int top[maxn],sz[maxn],dep[maxn],fa[maxn][20],son[maxn];
int sgn(double x) { if (x>eps) return 1; if (x<-eps) return -1; return 0; }
void add(int x,int y) { tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; }
void dfs1(int u,int p) {
	fa[u][0]=p,dep[u]=dep[p]+1,sz[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p) continue;
		dfs1(v,u); sz[u]+=sz[v];
		if (!son[u]||sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int p) {
	if (son[u]) { top[son[u]]=top[u]; dfs2(son[u],u); }
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v==p||v==son[u]) continue;
		top[v]=v,dfs2(v,u);
	}
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--) if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int flag;
double cur;
struct node {
	double k,b,l,r;
	double f(double x) { return k*x+b; }
	friend bool operator < (node t1,node t2) {
		double tmp=sgn(t1.f(cur)-t2.f(cur));
		if (tmp!=0) return tmp<0;
		tmp=max(t1.l,t2.l);
		if (sgn(t1.f(tmp)-t2.f(tmp))) return sgn(t1.f(tmp)-t2.f(tmp))<0;
		if (sgn(t1.k-t2.k)) return sgn(t1.k-t2.k)<0;
		if (sgn(t1.b-t2.b)) return sgn(t1.b-t2.b)<0;
		if (sgn(t1.l-t2.l)) return sgn(t1.l-t2.l)<0;
		return sgn(t1.r-t2.r)<0;
	}
};
struct event {
	node l; double x; int op;
	friend bool operator < (event t1,event t2) {
		if (sgn(t1.x-t2.x)==0) {
			if (t1.op==t2.op) return t1.l<t2.l;
			return t1.op>t2.op;
		}
		return t1.x<t2.x;
	}
}; vector<event> g[maxn];
void add(int x,node A,double l,double r) {
	if (l>r) swap(l,r);
	A.l=l,A.r=r;
	g[x].push_back((event){A,l,1});
	g[x].push_back((event){A,r,-1});
}
multiset<node> S;
multiset<node>::iterator it,it1,it2;
double res;
void update(node A,node B) {
	double l=max(A.l,B.l),r=min(A.r,B.r);
	if (sgn(l-r)>0) return;
	if (sgn(A.k-B.k)==0) {
		if (sgn(A.b-B.b)==0) res=min(res,l);
		return;
	}
	double tmp=(A.b-B.b)/(B.k-A.k);
	if (sgn(tmp-l)>=0&&sgn(r-tmp)>=0) res=min(res,tmp);
}
double solve(vector<event> &G) {
	S.clear();
	sort(G.begin(),G.end());
	res=INF;
	cur=-INF;
	for (int i=0;i<G.size();i++) {
		if (sgn(G[i].x-res)>0) break;
		cur=G[i].x;
		if (G[i].op==1) {
			it=S.upper_bound(G[i].l);
			if (it!=S.end()) update(*it,G[i].l);
			if (it!=S.begin()) {
				it--;
				update(*it,G[i].l);
			}
			S.insert(G[i].l);
		} else {
			S.erase(S.lower_bound(G[i].l));
			it=S.upper_bound(G[i].l);
			if (it!=S.end()&&it!=S.begin()) {
				it2=it; it2--;
				update(*it,*it2);
			}
		}
	}
	return res;
}

void update(int x,int y,double s,double c,node A) {
	double s1;
	while (top[x]!=top[y]) {
		s1=s-(dep[x]-dep[top[x]]+1)/c;
		add(top[x],A,s,s1);
		s=s1;
		x=fa[top[x]][0];
	}
	if (x==y) return;
	flag=1;
	s1=s-(dep[x]-dep[y])/c;
	add(top[x],A,s,s1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y,t,z; double c,tmp,t2;
	for (int i=1;i<n;i++) read(x),read(y),add(x,y),add(y,x);
	dfs1(1,0),top[1]=1,dfs2(1,0);
	for (int i=1;i<=19;i++)
	for (int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	
	for (int i=1;i<=m;i++) {
		read(t),read(c),read(x),read(y);
		z=lca(x,y);
		tmp=t+(dep[x]+dep[y]-2*dep[z])*1.0/c;
		flag=0;
		if (x!=z) update(x,z,t,-c,(node){-c,dep[x]+c*t,-INF,INF});
		if (y!=z) update(y,z,tmp,c,(node){c,dep[y]-c*tmp,-INF,INF});
		if (!flag) {
			t2=t+(dep[x]-dep[z])*1.0/c;
			add(top[z],(node){c,dep[y]-c*tmp,-INF,INF},t2,t2);
		}
	}
	double ans=INF;
	for (int i=n;i>=1;i--)
		if (top[i]==i) ans=min(ans,solve(g[i]));
	if (sgn(ans-INF)>=0) puts("-1");
	else printf("%.10lf\n",ans);
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