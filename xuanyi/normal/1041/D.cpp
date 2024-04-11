#include <cstdio>

#define int long long

const int MAXN=200005;

int n,h,ans,x[MAXN],y[MAXN],w[MAXN];

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

#undef int
int main(){
#define int long long
	read(n),read(h);
	for (int i=1;i<=n;++i)
		read(x[i]),read(y[i]);
	for (int i=1;i<=n;++i)
		w[i]=x[i+1]-y[i]; w[n]=0;
	for (int i=1,j=1;i<=n;++i){
		h+=w[i-1];
		while (h>w[j] && j<n){
			h-=w[j++];
		}
		if (ans<y[j]-x[i]+h) ans=y[j]-x[i]+h;
	}
	print(ans);
	return 0;
}