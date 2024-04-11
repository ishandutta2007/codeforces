#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
const int maxm=(1.4e7)+10;
int n,m,a[maxn],ans[maxn],rt[maxn],tmp;
bool vis[maxn];
vector<int> g[maxn];
int S[maxn],tot,lst[maxn],tr[maxm],ls[maxm],rs[maxm];
void add(int x) {
	for (;x<=n;x+=x&(-x)) S[x]++;
}
int query(int x) {
	int res=0;
	for (;x;x-=x&(-x)) res+=S[x];
	return res;
}
void add(int x,int l,int r,int &root,int delta) {
	//printf("A %d %d\n",x,delta);
	tot++;
	ls[tot]=ls[root];
	rs[tot]=rs[root];
	tr[tot]=tr[root];
	root=tot;
	if (l==r) {
		tr[root]+=delta;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) add(x,l,mid,ls[root],delta);
	else add(x,mid+1,r,rs[root],delta);
	tr[root]=tr[ls[root]]+tr[rs[root]];
}
int query(int x,int l,int r,int root) {
	if (!root) return 0;
	if (l==r) return tr[root];
	//printf("OK %d %d %d\n",root,tr[root],x);
	int mid=(l+r)/2;
	if (x<=mid) return query(x,l,mid,ls[root])+tr[rs[root]];
	return query(x,mid+1,r,rs[root]);
}
int main() {
	//freopen("1.txt","r",stdin);
	//printf("MLE %d\n",(sizeof(tr)+sizeof(ls)+sizeof(rs)+sizeof(a)+sizeof(g)+sizeof(ans)+sizeof(rt))/1024/1024);
	read(n); read(m);
	for (int i=1;i<=m;i++) {
		read(a[i]);
		g[a[i]].push_back(i);
	}
	for (int i=1;i<=n;i++) ans[i]=i;
	int x,L,R;
	for (int i=1;i<=m;i++) {
		x=a[i];
		if (vis[x]) continue;
		vis[x]=1;
		ans[x]=x+query(n)-query(x);
	//	printf("OK %d %d %d\n",i,x,i-1-query(x));
		add(x);
	}
	for (int i=1;i<=m;i++) {
		x=a[i]; rt[i]=rt[i-1];
		if (lst[x]) add(lst[x],1,m,rt[i],-1);
		add(i,1,m,rt[i],1);
		lst[x]=i;
	}
	for (int i=1;i<=n;i++) {
		g[i].push_back(m+1);
		for (int j=1;j<g[i].size();j++) {
			L=g[i][j-1]+1,R=g[i][j]-1;
			if (L>R) continue;
			tmp=query(L,1,m,rt[R]);
		//	if (i==2) printf("L=%d R=%d tmp=%d\n",L,R,tmp);
			ans[i]=max(ans[i],tmp+1);
		}
	}
	int cnt=0;
	for (int i=n;i>=1;i--)
		if (!vis[i]) cnt++,ans[i]=n-cnt+1;
	for (int i=1;i<=n;i++) {
		if (vis[i]) printf("1 ");
		else printf("%d ",i);
		printf("%d\n",ans[i]);
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