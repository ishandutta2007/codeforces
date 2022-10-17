#include <cstdio>
typedef long long ll;

ll n,a,b,x;

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

inline int calc(ll x){
	int res=0;
	while (x){
		res+=x%10;
		x/=10;
	}
	return res;
}

int main(){
	read(n);
	x=9;
	while (n>=x){
		b+=x;
		n-=x;
		x*=10;
	}
	print(calc(n)+calc(b));
	return 0;	
}