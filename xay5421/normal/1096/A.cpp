#include <cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;

template <typename T>
void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

template <typename T>
void print(T x,int ch){
	print(x),putchar(ch);
}

int T,l,r;

int main(){
	read(T);
	while (T--){
		read(l),read(r);
		printf("%d %d\n",l,l*2);
	}
	return 0;
}