#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,d[1010],tot,len[1010];
vector<int> a[1010];
double c[1010][1010],f[1010][1010],g[1010][1010];
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=0;i<=1000;i++) {
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	read(n); read(m); int x,y;
	for (int i=1;i<=m;i++) {
		read(y); len[i]=y;
		while (y--) {
			read(x);
			a[i].push_back(x);
			d[++tot]=x;
		}
	}
	sort(d+1,d+tot+1);
	reverse(d+1,d+tot+1);
	f[0][0]=g[0][0]=1;
	for (int i=1;i<=m;i++) {
		x=y=0;
		for (int j=0;j<len[i];j++) {
			if (a[i][j]>d[n]) x++;
			if (a[i][j]>=d[n]) y++;
		}
		//printf("%d %d %d\n",x,y,len[i]);
		for (int j=0;j<=n;j++)
		for (int k=x;k<=y&&j+k<=n;k++) {
			//printf("%d %d %d %.3Lf %.3Lf\n",i-1,j,k,f[i-1][j],g[i-1][j]);
			g[i][j+k]+=g[i-1][j],
			f[i][j+k]+=f[i-1][j]/c[len[i]][k];
		}
	}
	printf("%.10lf\n",f[m][n]/g[m][n]);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/