#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(6e5)+10;
int n,q,tot,N,ans,nxt[maxn],head[maxn/2],to[maxn];
int top[maxn/2],sz[maxn/2],son[maxn/2];
int dep[maxn/2],fa[maxn/2],lg[maxn],dfn[maxn/2];
char S[maxn],s[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
struct string {
	int sa[maxn],rk[maxn];
	int SA[maxn],RK[maxn];
	int h[maxn],st[maxn][21];
	int cnt[maxn];
	void initSA() {
		for (int i=1;i<=N;i++) cnt[S[i]]++;
		for (int i='a';i<='z'+1;i++) cnt[i]+=cnt[i-1];
		for (int i=1;i<=N;i++) sa[cnt[S[i]]--]=i;
		for (int i=1;i<=N;i++) rk[sa[i]]=rk[sa[i-1]]+(S[sa[i]]!=S[sa[i-1]]);
		for (int j=1;j<=N;j*=2) {
			for (int i=1;i<=N;i++) cnt[rk[sa[i]]]=i;
			for (int i=N;i>=1;i--) if (sa[i]>j) SA[cnt[rk[sa[i]-j]]--]=sa[i]-j;
			for (int i=N;i>=1;i--) if (sa[i]>N-j) SA[cnt[rk[sa[i]]]--]=sa[i];
			for (int i=1;i<=N;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+j]!=rk[SA[i-1]+j]);
			for (int i=1;i<=N;i++) swap(sa[i],SA[i]),swap(rk[i],RK[i]);
			if (rk[sa[N]]>=N) break;
		}
	}
	int MN(int x,int y) {
		if (h[x]<h[y]) return x; return y;
	}
	void initH() {
		for (int i=1,j,lst=1;i<=N;i++) {
			j=sa[rk[i]-1]; if (lst) lst--;
			while (S[i+lst]==S[j+lst]) lst++;
			h[rk[i]]=lst;
		}
		for (int i=1;i<=N;i++) st[i][0]=h[i];
		for (int j=1;(1<<j)<=N;j++)
		for (int i=(1<<j);i<=N;i++)
			st[i][j]=min(st[i][j-1],st[i-(1<<(j-1))][j-1]);
	}
	int STQ(int l,int r) {
		if (l==r) return N;
		l=rk[l]; r=rk[r];
		if (l>r) swap(l,r);
		int j=lg[r-l];
		return min(st[r][j],st[l+(1<<j)][j]);
	}
} T;
void dfs(int u,int p) {
	sz[u]=1;
	fa[u]=p;
	dep[u]=dep[p]+1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if (sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int t) {
	dfn[u]=++N;
	S[N]=s[u];
	top[u]=t;
	if (son[u]) dfs2(son[u],t);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int x,int y) {
	while (top[x]!=top[y]) {
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (dep[x]<dep[y]) return x;
	return y;
}
vector<pair<int,int> > get() {
	vector<pair<int,int> > A,B;
	A.clear(); B.clear();
	int x,y,z;
	read(x); read(y); z=lca(x,y);
	while (top[x]!=top[z])
		A.push_back(make_pair(N-dfn[x]+1,dfn[x]-dfn[top[x]]+1)),x=fa[top[x]];
	A.push_back(make_pair(N-dfn[x]+1,dfn[x]-dfn[z]+1));
	while (top[y]!=top[z])
		B.push_back(make_pair(dfn[top[y]],dfn[y]-dfn[top[y]]+1)),y=fa[top[y]];
	if (y+z) B.push_back(make_pair(dfn[z]+1,dfn[y]-dfn[z]));
	for (int i=B.size()-1;i>=0;i--) A.push_back(B[i]);
	return A;
}
vector<pair<int,int> > A,B;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	int x,y,tmp;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y);
		add(y,x);
	}
	tot=0;
	dfs(1,0);
	dfs2(1,1);
	S[n+1]='z'+1;
	N=n*2+1;
	for (int i=n+2;i<=N;i++)
		S[i]=S[N-i+1];
	for (int i=2;i<=N;i++) lg[i]=lg[i/2]+1;
	T.initSA();
	T.initH();
	read(q);
	while (q--) {
		A=get(); B=get();
		x=0,y=0,ans=0;
		while (x<A.size()&&y<B.size()) {
			tmp=T.STQ(A[x].first,B[y].first);
			tmp=min(tmp,A[x].second);
			tmp=min(tmp,B[y].second);
			ans+=tmp;
			A[x].first+=tmp;
			A[x].second-=tmp;
			B[y].first+=tmp;
			B[y].second-=tmp;
			if (A[x].second&&B[y].second) break;
			if (!A[x].second) x++;
			if (!B[y].second) y++;
		}
		printf("%d\n",ans);
	}
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