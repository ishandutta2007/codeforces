#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=310;
int T,n,m,d[maxn][maxn];
bool flag;
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) read(d[i][j]);
		int cnt;
		flag=1;
		for (int i=1;i<=n&&flag;i++)
		for (int j=1;j<=m&&flag;j++) {
			cnt=0;
			for (int k=0;k<4;k++) {
				int a=i+fx[k][0],b=j+fx[k][1];
				if (1<=a&&a<=n&&1<=b&&b<=m) cnt++;
			}
			if (cnt<d[i][j]) flag=0;
			else d[i][j]=cnt;
		}
		if (!flag) printf("NO\n");
		else { printf("YES\n");
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=m;j++) printf("%d ",d[i][j]);
				printf("\n");
			}
		}
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