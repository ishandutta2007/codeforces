#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,k;

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	read(n),read(k);
	printf("%I64d\n",n>=k?k-1>>1:max(n-(k-n)+1>>1,0ll));
	return 0;
}