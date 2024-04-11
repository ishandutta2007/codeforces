#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

const int N=100005;

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

int n,s,tot,deg[N];

int main(){
	read(n),read(s);
	for (int i=1,u,v;i<n;++i) read(u),read(v),++deg[u],++deg[v];
	for (int i=1;i<=n;++i) if (deg[i]==1) ++tot;
	printf("%.10lf\n",(double)s/(double)tot*2);
	return 0;
}