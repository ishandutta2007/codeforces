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
typedef long long ll;
const int INF=1e9;
int T,n;
int dis[510][510];
int w[510][510];

int main() {
	read(T);
	while (T--) {
		read(n); int m; read(m);
		int x,y,z;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dis[i][j]=w[i][j]=INF;
		for (int i=1;i<=m;i++) {
			read(x),read(y),read(z);
			dis[x][y]=dis[y][x]=1;
			w[x][y]=w[y][x]=min(w[x][y],z);
		}
		for (int i=1;i<=n;i++) dis[i][i]=0;
		for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ll ans=1e18;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (dis[i][j]==1) {
			if (dis[1][i]<INF&&dis[j][n]<INF) ans=min(ans,(ll)w[i][j]*(dis[1][i]+dis[j][n]+1));
			for (int x=1;x<=n;x++) if (dis[i][x]<INF&&dis[1][x]<INF&&dis[x][n]<INF) ans=min(ans,(ll)w[i][j]*(dis[i][x]+dis[1][x]+dis[x][n]+2));
		}
		printf("%lld\n",ans);
	}
	return 0;
}