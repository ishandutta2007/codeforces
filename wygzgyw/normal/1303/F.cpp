#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e6)+10;
int n,m,q,tot,num[310][310],delta;
int d[310][310],ans[maxn],fa[100010];
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[310][310];
struct node { int x,y,id; };
vector<node> g1[maxn],g2[maxn];
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x);
	y=find(y);
	if (x==y) return;
	delta--;
	fa[x]=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(q);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		num[i][j]=++tot;
		g1[0].push_back((node){i,j,0});
	}
	int mx=0,a,b,c,x,y,z;
	for (int i=1;i<=q;i++) {
		read(a); read(b); read(c);
		mx=max(mx,c);
		if (d[a][b]==c) continue;
		g2[d[a][b]].push_back((node){a,b,i});
		d[a][b]=c;
		g1[d[a][b]].push_back((node){a,b,i});
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		g2[d[i][j]].push_back((node){i,j,q+1});
	for (int c=0;c<=mx;c++) {
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) vis[i][j]=0,fa[num[i][j]]=num[i][j];
		for (int i=0;i<g1[c].size();i++) {
			x=g1[c][i].x,y=g1[c][i].y;
			delta=1; vis[x][y]=1;
			for (int k=0;k<4;k++) {
				a=x+fx[k][0],b=y+fx[k][1];
				if (1<=a&&a<=n&&1<=b&&b<=m&&vis[a][b])
					merge(num[a][b],num[x][y]);
			}
			ans[g1[c][i].id]+=delta;
		}
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) vis[i][j]=0,fa[num[i][j]]=num[i][j];
		for (int i=g2[c].size()-1;i>=0;i--) {
			x=g2[c][i].x,y=g2[c][i].y;
			delta=1; vis[x][y]=1;
			for (int k=0;k<4;k++) {
				a=x+fx[k][0],b=y+fx[k][1];
				if (1<=a&&a<=n&&1<=b&&b<=m&&vis[a][b])
					merge(num[a][b],num[x][y]);
			}
			ans[g2[c][i].id]-=delta;
		}
	}
	for (int i=1;i<=q;i++) ans[i]+=ans[i-1],printf("%d\n",ans[i]);
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