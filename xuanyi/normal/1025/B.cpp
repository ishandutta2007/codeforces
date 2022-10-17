#include <cstdio>
typedef long long ll;
#define __R register

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

inline ll gcd(ll a,ll b){
	while (a^=b^=a^=b%=a,a);
	return b;
}

inline ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}

const int MAXN=150005;
const int MAXX=100005;
const int INF=2000000000;

int n,g=INF;
ll a,b,ta,tb,res;

inline void find(int x){
	if (x==2) res=2;
	for (int i=2;i*i<=x && i<g;i+=(i&1)+1){
		if (x%i==0){
			g=i;
			return;
		}
	}
	g=x;
}

int main(){
	read(n);
	read(a),read(b); res=lcm(a,b); ta=a,tb=b;
	for (__R int i=2;i<=n;i++){
		read(a),read(b);
		res=gcd(res,lcm(a,b));
	}
	if (res==1) return puts("-1"),0;
	if (ta!=1 && res%ta==0) find(ta);
	if (tb!=1 && res%tb==0) find(tb);
	for (__R int i=2;i*i<=res && i*i<=g;i+=(i&1)+1){
		if (res%i==0) return print(i),0;
	}
	if (g!=INF) return print(g),0;
	print(res);
	return 0;
}