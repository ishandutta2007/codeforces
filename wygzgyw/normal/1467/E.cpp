#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,a[maxn],tot,head[maxn],nxt[maxn*2],to[maxn*2];
map<int,int> cnt;
void add(int x,int y) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y;
}
map<int,int> A;
int delta[maxn],rt;
void dfs1(int u,int p) {
	map<int,int> B;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs1(v,u);
		if (A[a[u]]) delta[rt]++,delta[v]--,delta[A[a[u]]]++;
		if ((int)A.size()>(int)B.size()) swap(A,B);
		for (pair<int,int> x : A) if (x.second) {
			if (B[x.first]) delta[x.second]++,delta[B[x.first]]++;
			B[x.first]=x.second;
		}
	}
	B[a[u]]=u;
	swap(A,B);
}
int ans;
void dfs2(int u,int p) {
	delta[u]+=delta[p];
	if (delta[u]==0) ans++;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs2(v,u);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		add(x,y),add(y,x);
	}
	rt=-1;
	for (int i=1;i<=n;i++) if (cnt[a[i]]==1) { rt=i; break; }
	if (rt==-1) { puts("0"); return 0; }
	dfs1(rt,0);
	dfs2(rt,0);
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