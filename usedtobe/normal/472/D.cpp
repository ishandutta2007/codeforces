#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define fail return puts("NO"),0
#define N 2005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
int d[N][N],n;
int main() {
	read(n);rep(i,1,n)rep(j,1,n)read(d[i][j]);
	rep(i,1,n)if(d[i][i])fail;rep(i,1,n)rep(j,1,n)if(d[i][j]!=d[j][i])fail;
	rep(i,1,n)rep(j,1,n)if(i!=j&&d[i][j]==0)fail;
	rep(i,1,n) {
		int pos=1;rep(j,1,n)if(i!=j&&d[i][pos]>d[i][j])pos=j;
		rep(j,1,n)if(abs(d[i][j]-d[pos][j])!=d[i][pos])fail;
	}
	puts("YES");
	return 0;
}