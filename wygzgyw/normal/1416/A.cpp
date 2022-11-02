#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(3e5)+10;
int T,n,ans[maxn],x;
vector<int> g[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n+1;i++) g[i].clear(),g[i].push_back(0);
		for (int i=1;i<=n;i++) read(x),g[x].push_back(i);
		for (int i=1;i<=n+1;i++) g[i].push_back(n+1),ans[i]=INF;
		for (int i=1;i<=n;i++) {
			int mx=0;
			for (int j=1;j<g[i].size();j++) {
				mx=max(mx,g[i][j]-g[i][j-1]-1);
			}
			ans[mx+1]=min(ans[mx+1],i);
		}
		for (int i=2;i<=n;i++) ans[i]=min(ans[i],ans[i-1]);
		for (int i=1;i<=n;i++)
			if (ans[i]==INF) printf("-1 ");
			else printf("%d ",ans[i]);
		puts("");
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