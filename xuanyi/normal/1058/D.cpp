#include <cstdio>

#define int long long

int n,m,k,N,M,K,g;
bool flag=0;

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

inline int gcd(int a,int b){
	while (a^=b^=a^=b%=a,a);
	return b;
}

#undef int
int main(){
#define int long long
	read(n),read(m),read(k);
	N=n,M=m,K=k;
	g=gcd(n,k); n/=g,k/=g;
	g=gcd(m,k); m/=g,k/=g;
	if (k==1){
		if (n*2<=N){
			puts("YES");
			print(0),putchar(' '),print(0),putchar('\n');
			print(n*2),putchar(' '),print(0),putchar('\n');
			print(0),putchar(' '),print(m),putchar('\n');
			return 0;
		}
		if (m*2<=M){
			puts("YES");
			print(0),putchar(' '),print(0),putchar('\n');
			print(n),putchar(' '),print(0),putchar('\n');
			print(0),putchar(' '),print(m*2),putchar('\n');
			return 0;
		}
	}
	if (k==2){
		puts("YES");
		print(0),putchar(' '),print(0),putchar('\n');
		print(n),putchar(' '),print(0),putchar('\n');
		print(0),putchar(' '),print(m),putchar('\n');
		return 0;
	}
	return puts("NO"),0;
}