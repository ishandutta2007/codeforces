#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

const int N=100005;

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

int n,tot;
bool used[1005][1005];

struct po{
	int x,y;
	bool operator <(const po &b)const{return x<b.x||(x==b.x&&y<b.y);}
} a[3];

int main(){
	for (int i=1;i<=3;++i) read(a[i].x),read(a[i].y);
	std::sort(a+1,a+1+3);
	rep (i,a[1].x,a[2].x) used[i][a[1].y]=1;
	per (i,a[3].x,a[2].x) used[i][a[3].y]=1;
	int mn=std::min(std::min(a[1].y,a[2].y),a[3].y),mx=std::max(std::max(a[1].y,a[2].y),a[3].y);
	rep (i,mn,mx) used[a[2].x][i]=1;
	for (int i=0;i<=1000;++i)
		for (int j=0;j<=1000;++j) if (used[i][j]) ++tot;
	printf("%d\n",tot);
	for (int i=0;i<=1000;++i)
		for (int j=0;j<=1000;++j) if (used[i][j]) printf("%d %d\n",i,j);
	return 0;
}