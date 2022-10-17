#include <cstdio>

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putc(x%10+48);
}

int n,ha[256];

inline char readc(){
	char ch;
	while (ch=getchar(),ch<'a' || 'z'<ch);
	return ch;
}

int main(){
	read(n);
	if (n==1) return puts("Yes"),0;
	for (int i=1;i<=n;i++){
		if (++ha[readc()]>1) return puts("Yes"),0;
	}
	puts("No");
	return 0;
}