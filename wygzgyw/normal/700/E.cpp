#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(4e5)+10;
int n,lst,cnt,a[maxn][30],id[maxn],l[maxn],fa[maxn];
char s[maxn];
queue<int> q;
int tot,d[maxn],in[maxn],rt[maxn],ans,dp[maxn],pos[maxn];
void extend(int i,int c) {
	int p=lst,np=lst=++cnt;
	l[np]=l[p]+1; id[np]=i;
	while (p&&!a[p][c])
		a[p][c]=np,p=fa[p];
	if (p==0) fa[np]=1;
	else {
		int q=a[p][c];
		if (l[p]+1==l[q]) fa[np]=q;
		else {
			int nq=++cnt;
			l[nq]=l[p]+1; id[nq]=i;
			memcpy(a[nq],a[q],sizeof(a[q]));
			fa[nq]=fa[q];
			fa[np]=fa[q]=nq;
			while (a[p][c]==q) a[p][c]=nq,p=fa[p];
		}
	}
}
int ls[maxn*50],rs[maxn*50];
void add(int l,int r,int x,int &root) {
	if (!root) root=++tot;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(l,mid,x,ls[root]);
	else add(mid+1,r,x,rs[root]);
}
int merge(int x,int y) {
	if (!x||!y) return x+y;
	int z=++tot;
	ls[z]=merge(ls[x],ls[y]);
	rs[z]=merge(rs[x],rs[y]);
	return z;
}
bool query(int L,int R,int l,int r,int root) {
	if (!root) return 0;
	if (L<=l&&r<=R) return 1;
	int mid=(l+r)/2;
	if (L<=mid&&query(L,R,l,mid,ls[root])) return 1;
	if (mid<R&&query(L,R,mid+1,r,rs[root])) return 1;
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	lst=cnt=1;
	for (int i=1;i<=n;i++) extend(i,s[i]-'a');
	for (int i=1;i<=cnt;i++) in[fa[i]]++;
	for (int i=1;i<=cnt;i++) if (!in[i]) q.push(i);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		d[++tot]=u;
		u=fa[u];
		in[u]--;
		if (!in[u]) q.push(u);
	}
	int L,R,u;
	tot=0;
	for (int i=1;i<cnt;i++) {
		u=d[i];
		add(1,n,id[u],rt[u]);
		rt[fa[u]]=merge(rt[fa[u]],rt[u]);
	}
	for (int i=cnt-1;i>=1;i--) {
		u=d[i];
		if (fa[u]==1) dp[u]=1,pos[u]=u;
		else {
			L=id[u]-l[u]+l[pos[fa[u]]];
			R=id[u]-1;
			if (query(L,R,1,n,rt[pos[fa[u]]]))
				dp[u]=dp[fa[u]]+1,pos[u]=u;
			else dp[u]=dp[fa[u]],pos[u]=pos[fa[u]];
		}
		ans=max(ans,dp[u]);
	}
	printf("%d\n",ans);
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