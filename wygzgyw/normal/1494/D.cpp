#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=3010;
const int INF=1e9;
int n,tot,mn[maxn],son[maxn];
int d[maxn][maxn],e[maxn][maxn],now;
vector<pair<int,int> > edge;
int ans[maxn],fa[maxn];
vector<int> bel[maxn];
int id[maxn],bad[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
int rub[maxn],N,dep[maxn],ID[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) read(d[i][j]);
	tot=n;
	for (int i=1;i<=n;i++) id[i]=i;
	int T=0;
	while (1) {
		if (n==1) {
			ans[id[1]]=d[1][1]; break;
		}
		int mx=0;
		for (int i=1;i<=n;i++) {
			mn[i]=INF; N=0;
			for (int j=1;j<=n;j++) if (i!=j) mn[i]=min(mn[i],d[i][j]),rub[++N]=d[i][j];
			sort(rub+1,rub+N+1),N=unique(rub+1,rub+N+1)-rub-1;
			dep[i]=N; mx=max(mx,dep[i]);
			ans[id[i]]=d[i][i];
			fa[i]=i;
		}
		
		/*printf("---\n");
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) printf("%d ",d[i][j]); puts("");
		}
		printf("---\n");
		*/
		for (int i=1;i<=n;i++) if (dep[i]==mx) {
			for (int j=i+1;j<=n;j++) if (dep[j]==mx) {
				if (mn[i]==mn[j]&&d[i][j]==mn[i]) {
					fa[find(i)]=find(j);
				//	printf("? %d %d\n",i,j);
				}
			}
		}
		for (int i=1;i<=n;i++) bel[i].clear();
		for (int i=1;i<=n;i++) bel[find(i)].push_back(i);
		now=0;
		for (int i=1;i<=n;i++) if (bel[i].size()) {
			if ((int)bel[i].size()>1) {
				tot++;
				now++; bad[now]=1;
				for (int j=0;j<bel[i].size();j++) edge.push_back(make_pair(id[bel[i][j]],tot));
				son[now]=i;
				ID[now]=tot;
			} else {
				now++;
				son[now]=i; bad[now]=0;
				ID[now]=id[i];
			}
			
		}
		n=now;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j) e[i][j]=d[son[i]][son[j]];
			else if (bad[i]) e[i][j]=mn[son[i]];
			else e[i][j]=d[son[i]][son[j]];
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]=e[i][j];
		for (int i=1;i<=n;i++) id[i]=ID[i];
		//T++; if (T==3) break;
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",ans[i]); puts("");
	printf("%d\n",id[1]);
	for (int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].first,edge[i].second);
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