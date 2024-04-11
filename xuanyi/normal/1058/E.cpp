#include <cstdio>
typedef long long ll;

const int MAXN=300005;

int n,a[MAXN],cnt[2];
ll res,s[MAXN];

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
	read(n); cnt[0]=1; ll x;
	for (int i=1;i<=n;++i) ++cnt[(s[i]=s[i-1]+(a[i]=__builtin_popcountll((read(x),x))))&1];
	res=(ll)cnt[0]*(cnt[0]-1)/2+(ll)cnt[1]*(cnt[1]-1)/2;
	for (int i=1,mx;i<=n;++i){
		mx=0;
		for (int j=0;j<=64 && i+j<=n;++j){
			if (mx<a[i+j]) mx=a[i+j];
			if (!(s[i+j]-s[i-1]&1) && s[i+j]-s[i-1]<mx*2) --res;
		}
	}
	print(res);
}