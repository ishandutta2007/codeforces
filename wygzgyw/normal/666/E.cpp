#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(2e6)+10;
const int maxm=(1e7)+10;
int n,m,q,cnt,tot,ls[maxm],rs[maxm];
char s[maxn];
int rt[maxn],POS[maxn],rub;
int lst,len[maxn],fa[maxn],f[maxn][23],a[maxn][26];
pair<int,int> tr[maxm];
void pushup(int root) {
	tr[root]=max(tr[ls[root]],tr[rs[root]]);
}
void add(int x,int l,int r,int &root) {
	if (!root) root=++tot;
	if (l==r) { tr[root].first++,tr[root].second=-l; return; }
	int mid=(l+r)>>1;
	if (x<=mid) add(x,l,mid,ls[root]);
	else add(x,mid+1,r,rs[root]);
	pushup(root);
}
void insert(int c,int id) {
	int p=lst,np=lst=++cnt;
	len[np]=len[p]+1;
	if (!id) POS[++rub]=np;
	else add(id,1,m,rt[np]);
	while (a[p][c]==0&&p!=0)
		a[p][c]=np,p=fa[p];
	if (p==0) fa[np]=1;
	else {
		int q=a[p][c];
		if (len[p]+1==len[q]) fa[np]=q;
		else {
			int nq=++cnt; len[nq]=len[p]+1;
			memcpy(a[nq],a[q],sizeof(a[q]));
			fa[nq]=fa[q];
			fa[np]=fa[q]=nq;
			while (a[p][c]==q) a[p][c]=nq,p=fa[p];
		}
	}
}
int merge(int l,int r,int x,int y) {
	if (!x||!y) return x+y;
	int root=++tot;
	if (l==r) {
		tr[root]=make_pair(tr[x].first+tr[y].first,-l); return root;
	}
	int mid=(l+r)>>1;
	ls[root]=merge(l,mid,ls[x],ls[y]);
	rs[root]=merge(mid+1,r,rs[x],rs[y]);
	pushup(root);
	return root;
}
vector<int> g[maxn];
void dfs(int u) {
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		dfs(v);
		rt[u]=merge(1,m,rt[u],rt[v]);
	}
}
pair<int,int> query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1; pair<int,int> res=make_pair(-INF,-INF);
	if (L<=mid) res=query(L,R,l,mid,ls[root]);
	if (mid<R) res=max(res,query(L,R,mid+1,r,rs[root]));
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	lst=cnt=1;
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) insert(s[i]-'a',0);
	//printf("OK %d\n",cnt);
	read(m);
	for (int i=1;i<=m;i++) {
		scanf("%s",s+1); n=strlen(s+1); lst=1;
		for (int j=1;j<=n;j++) insert(s[j]-'a',i);
	}
	for (int i=2;i<=cnt;i++) g[fa[i]].push_back(i),f[i][0]=fa[i];
	for (int i=1;i<=22;i++) for (int j=1;j<=cnt;j++) f[j][i]=f[f[j][i-1]][i-1];
	dfs(1);
	read(q);
	int x,y,l,r,u,Len; pair<int,int> ans;
	while (q--) {
		read(x),read(y),read(l),read(r);
		u=POS[r],Len=r-l+1;
		for (int i=22;i>=0;i--) if (f[u][i]&&len[f[u][i]]>=Len) u=f[u][i];
		ans=query(x,y,1,m,rt[u]);
		if (ans.first==0) printf("%d %d\n",x,0);
		else printf("%d %d\n",-ans.second,ans.first);
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