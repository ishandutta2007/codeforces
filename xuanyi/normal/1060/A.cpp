#include <cstdio>
#include <algorithm>

const int MAXN=105;

int n,cnt;
char s[MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	register int i;
	read(n);
	scanf("%s",s);
	for (i=0;i<n;++i) if (s[i]=='8') ++cnt;
	printf("%d\n",std::min(cnt,n/11));
	return 0;	
}