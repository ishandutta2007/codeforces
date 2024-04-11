#include <cstdio>
#include <algorithm>
typedef long long ll;

const int MAXN=100005;

int n;
int l[MAXN],r[MAXN];
ll ans;

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
	register int i;
	read(n);
	for (i=1;i<=n;++i) read(l[i]),read(r[i]);
	std::sort(l+1,l+1+n);
	std::sort(r+1,r+1+n);
	for (i=1;i<=n;++i) ans+=std::max(l[i],r[i]);
	print(ans+n);
	return 0;
}