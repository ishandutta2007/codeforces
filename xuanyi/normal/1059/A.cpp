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

int n,L,a,ans;

int main(){
	register int i,l,r,t,lst=0;
	read(n),read(L),read(a);
	for (i=1;i<=n;++i){
		read(l),read(t);
		r=l+t;
		ans+=(l-lst)/a;
		lst=r;
	}
	printf("%d\n",ans+(L-lst)/a);
	return 0;	
}