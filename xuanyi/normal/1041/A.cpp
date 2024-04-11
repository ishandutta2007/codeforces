#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=1005;

int n,a[MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	printf("%d\n",a[n]-a[1]-n+1);
	return 0;
}