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
const int maxn=(1e5)+10;
int n,dp[maxn],ans,dep[maxn];
vector<int> g[maxn],pre[maxn],suf[maxn];
void dfs(int u,int p) {
	vector<int> s; dep[u]=dep[p]+1;
	for (int v : g[u]) if (v!=p) {
		dfs(v,u);
		s.push_back(dp[v]);
	}
	sort(s.begin(),s.end()); reverse(s.begin(),s.end());
	if (!p) {
		dp[u]=0;
		for (int i=1;i<s.size();i++) dp[u]=max(dp[u],s[i]+i-1);
		if (!s.empty()) dp[u]+=s[0];
	} else {
		dp[u]=1;
		for (int i=0;i<s.size();i++) dp[u]=max(dp[u],s[i]+i);
	}
}
void dfs2(int u,int p,int from) {
	vector<pair<int,int> > s;
	for (int v : g[u]) if (v!=p) s.push_back(MP(dp[v],v));
	if (p) s.push_back(MP(from,p));
	sort(s.begin(),s.end()); reverse(s.begin(),s.end());
	int now=0;
	for (int i=1;i<s.size();i++) now=max(now,s[i].first+i-1);
	if (!s.empty()) now+=s[0].first;
	ans=max(ans,now);
	pre[u].resize((int)g[u].size()),suf[u].resize((int)g[u].size());
	for (int i=0,v;i<s.size();i++) {
		v=s[i].second; if (i) pre[u][i]=pre[u][i-1]; else pre[u][i]=0;
		pre[u][i]=max(pre[u][i],s[i].first+i);
	}
	for (int i=(int)s.size()-1,v;i>=0;i--) {
		v=s[i].second; if (i==(int)s.size()-1) suf[u][i]=0; else suf[u][i]=suf[u][i+1];
		suf[u][i]=max(suf[u][i],s[i].first+i);
	}
	for (int i=0,v;i<(int)s.size();i++) {
		v=s[i].second; if (v==p) continue;
		now=1; if (i) now=max(now,pre[u][i-1]); if (i<(int)s.size()-1) now=max(now,suf[u][i+1]-1);
		dfs2(v,u,now);
	}
}
int query(int x) {
	printf("? %d\n",x); fflush(stdout);
	scanf("%d",&x); return x;
}
int solve(int u,int p) {
	vector<pair<int,int> > s;
	for (int v : g[u]) if (v!=p) s.push_back(MP(dp[v],v));
	if (s.empty()&&p) return query(u);
	sort(s.begin(),s.end()); reverse(s.begin(),s.end());
	if (!p) {
		int x=0,y=0;
		for (pair<int,int> A : s) {
			int res=solve(A.second,u);
			if (res&&dep[res]!=dep[u]) {
				if (!x) x=res; else { y=res; break; }
			}
		}
		if (!x) x=u; if (!y) y=u;
		printf("! %d %d\n",x,y); fflush(stdout); exit(0);
	}
	for (pair<int,int> A : s) {
		int res=solve(A.second,u);
		if (dep[res]!=dep[u]) return res;
	}
	return u;
}
int main() {
	scanf("%d",&n); int x,y;
	for (int i=1;i<n;i++) scanf("%d %d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	dfs2(1,0,0);
	printf("%d\n",ans); fflush(stdout);
	int f;
	scanf("%d",&f);
	dfs(f,0);
	solve(f,0);
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