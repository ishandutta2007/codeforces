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

const int MAXN=1000005;

int n;

//int n,g,s,t;
//int a[MAXN],p[MAXN],vis[MAXN];

//void pre(){
//	vis[0]=vis[1]=1;
//	for (int i=1;i<=n;++i){
//		if (!vis[i]) p[++p[0]]=i;
//		for (int j=1;j<=p[0] && i*p[j]<=n;++j){
//			vis[i*p[j]]=1;
//			if (i%p[j]==0) break;
//		}
//	}
//}

int main(){
	register int i,j;
	read(n); int m=n,now=1;
//	pre();
//	for (i=1;i<=n;++i) a[i]=1;
	while (m>1){
		for (int i=1;i<=(m+1>>1);++i) print(now),putchar(' ');
		m=m-(m+1>>1);
		if (m>1) now<<=1;
	}
	print(n/now*now),putchar('\n');
	return 0;
}