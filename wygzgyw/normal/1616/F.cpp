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
int T,n,m;
int g[100][100],col[300];
vector<vector<int> > a;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) g[i][j]=-1;
		int x,y,z;
		for (int i=0;i<m;i++) {
			read(x),read(y),read(z);
			g[x][y]=g[y][x]=i; col[i]=z;
		}
		a.clear();
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) for (int k=j+1;k<=n;k++) {
			int a=g[i][j],b=g[j][k],c=g[k][i];
			if (a!=-1&&b!=-1&&c!=-1) {
				vector<int> V(m+1); V[a]=V[b]=V[c]=1; ::a.push_back(V);
			}
		}
		for (int i=0;i<m;i++) if (col[i]!=-1) {
			vector<int> V(m+1);
			V[i]=1; V[m]=col[i]%3; a.push_back(V);
		}
		int tot=(int)a.size(),flag=1;
	//	for (int i=0;i<tot;i++) printf("%d ",(int)a[i].size()); puts("");
	/*for (int i=0;i<tot;i++) {
		for (int j=0;j<=m;j++) printf("%d ",a[i][j]); puts("");
	}
	puts("");*/
		for (int i=0;i<tot;i++) {
			int j; for (j=0;j<=m;j++) if (a[i][j]) break;
			if (j>m) {
				swap(a[i],a.back());
				a.pop_back(); tot--; i--; continue;
			}
			if (j==m) { flag=0; break; }
			if (a[i][j]==2) { for (int &x : a[i]) x=(3-x)%3; }
			for (int k=0;k<tot;k++) if (k!=i&&a[k][j]) {
				int tmp=a[k][j];
				//printf("? %d\n",(int)a[k].size());
				for (int l=0;l<=m;l++) a[k][l]=(a[k][l]-tmp*a[i][l]+9)%3;
			}
		}
	/*for (int i=0;i<tot;i++) {
		for (int j=0;j<=m;j++) printf("%d ",a[i][j]); puts("");
	}
	puts("");*/
		if (!flag) puts("-1");
		else {
			for (int i=0;i<tot;i++) for (int j=0;j<m;j++) if (a[i][j]) { col[j]=a[i][m]; break; }
			for (int j=0;j<m;j++) { if (-1==col[j]) col[j]=3; else if (col[j]==0) col[j]=3; printf("%d ",col[j]); } puts("");
		}
	}
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