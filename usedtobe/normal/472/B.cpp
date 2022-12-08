#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define N 2005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
int n,ans,f[N],k;
int main() {  
	read(n,k);rep(i,1,n)read(f[i]);sort(f+1,f+n+1);
	for(int i=n;i>0;i-=k) ans+=f[i]-1;
	printf("%d\n",ans*2);
	return 0;
}