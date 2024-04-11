#include <cstdio>

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

const int MAXN=1005;

int n,m;
int a[MAXN][MAXN],b[MAXN][MAXN];

int main(){
	register int i,j;
	read(n),read(m);
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j){
			char ch=getchar();
			while (ch!='#' && ch!='.') ch=getchar();
			a[i][j]=ch=='#';
		}
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (a[i+1][j] && a[i][j+1] && a[i+1][j+1] && a[i-1][j] && a[i][j-1] && a[i-1][j-1] && a[i-1][j+1] && a[i+1][j-1])
				b[i+1][j]=b[i][j+1]=b[i+1][j+1]=b[i-1][j]=b[i][j-1]=b[i-1][j-1]=b[i-1][j+1]=b[i+1][j-1]=1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] && !b[i][j])
				return puts("NO"),0;
	puts("YES");
	return 0;	
}