#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,x,to[maxn],head[maxn],nxt[maxn],tot;
int dep[maxn],cnt[maxn],dp[maxn],c,from[maxn];
map<int,vector<int> > g;
char ans[maxn];
int mxdep,son[maxn],fa[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y; son[x]++;
}
void dfs(int u) {
	dep[u]=dep[fa[u]]+1; mxdep=max(mxdep,dep[u]);
	cnt[dep[u]]++;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		dfs(v);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(x);
	for (int i=2;i<=n;i++) read(fa[i]),add(fa[i],i);
	dfs(1);
	for (int i=1;i<=n;i++) if (cnt[i]) g[cnt[i]].push_back(i);
	dp[0]=1;
	for (auto &it : g) {
		for (int j=0;j<it.first;j++) {
			c=0;
			for (int k=j;k<=n;k+=it.first) {
				if (dp[k]) c=it.second.size();
				else if (c) {
					dp[k]=1;
					c--;
					from[k]=it.second[c];
				} 
			}
		}
	}
	for (int i=1;i<=n;i++) ans[i]='b';
	if (dp[x]) {
		while (x) {	
			ans[from[x]]='a';
			x-=cnt[from[x]];
		}
		printf("%d\n",mxdep);
		for (int i=1;i<=n;i++) putchar(ans[dep[i]]); puts(""); return 0;
	}
	for (int i=1;i<=n;i++)
		if (x>=cnt[i]) x-=cnt[i],ans[i]='a';
	int id;
	for (int i=n;i>=1;i--)
		if (ans[i]=='b') { id=i; break; }
	printf("%d\n",mxdep+1);
	for (int i=1;i<=n;i++) {
		if (son[i]) putchar(ans[dep[i]]);
		else if (dep[i]==id&&x) putchar('a'),x--;
		else putchar(ans[dep[i]]);
	}
	puts("");
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