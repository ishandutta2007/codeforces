#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,m,block,N,b[maxn];
vector<int> a[maxn],g[maxn];
int vis[maxn];
int cnt;
bool solve() {
	for (int i=1;i<=N;i++) vis[i]=0;
	for (int i=1;i<=n;i++) {
		if ((int)a[i].size()>block) {
			for (int x : a[i]) vis[x]=1;
			for (int j=1;j<=n;j++) if (i!=j) {
				cnt=0;
				for (int x : a[j]) if (vis[x]) {
					cnt++;
					if (cnt>=2) {
						printf("%d %d\n",i,j);
						return 1;
					}
				}
			}
			for (int j=0;j<a[i].size();j++) vis[a[i][j]]=0;
		} else {
			for (int x : a[i]) g[x].push_back(i);
		}
	}
	for (int i=1;i<=N;i++) {
		for (int x : g[i]) {
			for (int y : a[x]) if (i!=y) {
				if (vis[y]) { printf("%d %d\n",x,vis[y]); return 1; }
				vis[y]=x;
			}
		}
		for (int x : g[i]) {
			for (int y : a[x]) if (i!=y) vis[y]=0;
		}
	}
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); int x,sz;
	while (T--) {
		read(n); m=0; N=0;
		for (int i=1;i<=n;i++) {
			read(sz);
			a[i].clear();
			m+=sz;
			while (sz--) read(x),a[i].push_back(x),b[++N]=x;
		}
		sort(b+1,b+N+1); N=unique(b+1,b+N+1)-b-1;
		for (int i=1;i<=N;i++) g[i].clear();
		for (int i=1;i<=n;i++)
		for (int j=0;j<a[i].size();j++) {
			a[i][j]=lower_bound(b+1,b+N+1,a[i][j])-b;
		}
		block=ceil(sqrt(m*1.0));		
		if (!solve()) puts("-1");
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