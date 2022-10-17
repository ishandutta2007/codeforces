#include <cmath>
#include <cstdio>
typedef int INT;
#define int long long 

const int MAXN=100005;
const int INF=0X7FFFFFFF;

int n,k,R,f[MAXN][35],g[MAXN][35],h[MAXN][35];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

INT main(){
	read(n),read(k); R=log2(k);
	for (int i=1;i<=n;i++) read(f[i][0]),++f[i][0];
	for (int i=1;i<=n;i++) read(g[i][0]),h[i][0]=g[i][0];
	for (int j=1;j<=R;j++)
		for (int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
			g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
			if (h[i][j-1]<h[f[i][j-1]][j-1]) h[i][j]=h[i][j-1];
			else h[i][j]=h[f[i][j-1]][j-1];
		}
	for (int i=1;i<=n;i++){
		int s=0,m=INF,t=k,u=i;
		for (int j=R;j>=0;j--)
			if (t>>j&1){
				if (h[u][j]<m) m=h[u][j];
				s=s+g[u][j];
				u=f[u][j];
			}
		print(s),putchar(' '),print(m),putchar('\n');
	}
	return 0;
}