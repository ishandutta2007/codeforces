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
const int maxn=(3e5)+10;
int n,m,p[maxn],d[maxn],X[maxn],Y[maxn];
int pos[maxn],vis[maxn],tot;
vector<pair<int,int> > g[maxn];
int S;
bool cmp(pair<int,int> A,pair<int,int> B) {
	int a=(pos[A.first]-S+tot)%tot,b=(pos[B.first]-S+tot)%tot;
	return a<b;
}
vector<int> G[maxn];
int hd,tl,q[maxn],in[maxn];
void link(int x,int y) {
	in[y]++;
	G[x].push_back(y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(p[i]);
	for (int i=1;i<=m;i++) {
		read(X[i]),read(Y[i]);
		g[X[i]].push_back(MP(Y[i],i));
		g[Y[i]].push_back(MP(X[i],i));
	}
	for (int i=1;i<=n;i++) if (!vis[i]) {
		int x=i; tot=0;
		while (!vis[x]) d[tot]=x,pos[x]=tot,tot++,vis[x]=1,x=p[x];
		for (int j=0;j<tot;j++) {
			x=d[j]; S=j;
			sort(g[x].begin(),g[x].end(),cmp);
			for (int k=0;k+1<(int)g[x].size();k++) {
				link(g[x][k].second,g[x][k+1].second);
			}
		}
	}
	for (int i=1;i<=m;i++) if (!in[i]) q[++tl]=i; hd=1;
	while (hd<=tl) {
		int x=q[hd]; hd++;
		for (int &y : G[x]) {
			in[y]--; if (!in[y]) q[++tl]=y;
		}
	}
	for (int i=1;i<=tl;i++) {
		printf("%d ",q[i]);
		swap(p[X[q[i]]],p[Y[q[i]]]);
	} puts("");
	//for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
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