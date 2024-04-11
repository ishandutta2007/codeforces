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
const int maxn=(1e7)+10;
int n,m;
int fa[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int w[maxn];
struct node {
	int x,i,j;
} d[maxn/8]; int tot;
bool cmp(node A,node B) { return A.x<B.x; }
int a[1010][1010];
int F(int x,int y,int k) {
	if (k==2) x++;
	if (k==1) y++;
	assert(1<=x&&x<=n+1&&1<=y&&y<=m+1);
	return (x*(m+2)+y)*4+k;
}
int cnt[maxn];
int ans[1010][1010];
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=0;i<=n+1;i++) for (int j=0;j<=m+1;j++) a[i][j]=1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int x; read(x);
			d[++tot]=(node){x,i,j};
			a[i][j]=x%2;
		}
	}
	sort(d+1,d+tot+1,cmp);
	for (int i=0;i<maxn;i++) fa[i]=i,w[i]=cnt[i]=1;
	for (int I=1;I<=tot;I++) {
		int x=d[I].i,y=d[I].j,now=0;
		for (int k=0;k<4;k++) {
			int xx=x+fx[k][0],yy=y+fx[k][1];
			int id=F(xx,yy,(k+2)%4);
			id=find(id);
			now^=w[id];
			if (a[x][y]) now^=cnt[id];
		//	printf("%d %d %d %d\n",x,y,cnt[id],w[id]);
		}
		ans[x][y]=now;
		for (int k=0;k<4;k++) {
			int xx=x+fx[k][0],yy=y+fx[k][1];
			int id2=find(F(xx,yy,(k+2)%4));
			int id=find(F(x,y,(k+2+now)%4));
			if (id==id2) continue;
//	printf("?? %d %d %d\n",k,w[id2],w[id]);
			if (a[x][y]) w[id]^=cnt[id2];
			fa[id2]=id;
			cnt[id]^=cnt[id2];
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) printf("%d",ans[i][j]); puts("");
	}
	return 0;
}