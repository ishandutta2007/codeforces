#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull A,B,X,Y; 

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


inline ull gcd(ull a,ull b){
	while (a^=b^=a^=b%=a,a);
	return b;
}

int main(){
	read(A),read(B),read(X),read(Y);
	ull t=gcd(X,Y);
	X/=t,Y/=t;
	print(min(A/X,B/Y));
	return 0;
}