#include <cstdio>

const int MAXN=105;

int T;
int n;
char _[MAXN];

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

int main(){
	read(T);
	while (T--){
		read(n); bool flag=1;
		scanf("%s",_);
		for (char *l=_,*r=_+n-1;l<r;l++,r--){
			if (*l!=*r && *l+2!=*r && *r+2!=*l){
				flag=0;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}