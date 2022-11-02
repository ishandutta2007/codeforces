#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,dis[3010][3010];
vector<int> g[3010];
int hd,tl,q[3010],vis[3010];
int ans,tmp,A,B,C,D,s;
int e[3010][3010],f[3010][3010];
bool cmp1(int x,int y) { return dis[s][x]>dis[s][y]; }
bool cmp2(int x,int y) { return dis[x][s]>dis[y][s]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); int x,y;
	while (m--) read(x),read(y),g[x].push_back(y);
	for (s=1;s<=n;s++) {
		for (int i=1;i<=n;i++) vis[i]=0;
		q[hd=tl=1]=s; vis[s]=1;
		while (hd<=tl) {
			x=q[hd]; hd++;
			for (int i=0;i<g[x].size();i++) {
				y=g[x][i];
				if (!vis[y]) q[++tl]=y,dis[s][y]=dis[s][x]+1,vis[y]=1;
			}
		}
	}
	for (s=1;s<=n;s++) {
		for (int i=1;i<=n;i++) e[s][i]=f[s][i]=i;
		sort(e[s]+1,e[s]+n+1,cmp1),sort(f[s]+1,f[s]+n+1,cmp2);
	}
	int a,d;
	for (int b=1;b<=n;b++)
	for (int c=1;c<=n;c++) if (b!=c&&dis[b][c]) {
		for (int x=1;x<=3;x++) for (int y=1;y<=3;y++) {
			a=f[b][x],d=e[c][y];
			if (a&&d&&a!=b&&dis[a][b]&&dis[c][d]&&a!=c&&a!=d&&b!=d&&c!=d) {
				tmp=dis[a][b]+dis[b][c]+dis[c][d];
				if (tmp>ans) ans=tmp,A=a,B=b,C=c,D=d;
			}
		}
	}
	printf("%d %d %d %d\n",A,B,C,D);
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