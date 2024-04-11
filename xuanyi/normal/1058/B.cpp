#include <cstdio>

int n,d,q;

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

int main(){
	read(n),read(d),read(q);
	for (int i=1,x,y;i<=q;++i){
		read(x),read(y);
		if (x-y>d || x-y<-d || x+y>n+n-d || x+y<d) puts("NO");
		else puts("YES");
	}
	return 0;
}