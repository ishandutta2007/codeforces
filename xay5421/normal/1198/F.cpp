//by xay5421 2449670833@qq.com
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<map>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;typedef unsigned long long ull;
template<typename T>inline void rd(T&x){int f=0,c;while(c=getchar(),c<48||57<c)f^=!(c^45);x=(c&15);while(c=getchar(),47<c&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
int gcd(int a,int b){if(!a)return b;if(!b)return a;while(a^=b^=a^=b%=a,a);return b;} 
const int N=100005;
int n,a[N],id[N],bel[N];std::map<int,int>mmp;
int brand(){
	return ((rand()&0x7fff)<<16)+((rand()&0x7fff)<<1)+(rand()&1);
}
signed main(){
	srand(time(0)^clock());
	rd(n);
	int len=0;
	rep(i,1,n){
		rd(a[i]);
		if(++mmp[a[i]]<=2)id[++len]=i;
		else bel[i]=1;
	}
	for(int _=1;_<=1000000/len;++_){
		for(int i=1;i<=len;++i){
			int u=brand()%len+1,v=brand()%len+1;
			if(u!=v)id[u]^=id[v]^=id[u]^=id[v];
		}
		int g1=0,g2=0;
		for(int i=1;i<=len;++i){
			int t=gcd(g1,a[id[i]]);
			if(t==g1)bel[id[i]]=2,g2=gcd(g2,a[id[i]]);
			else bel[id[i]]=1,g1=t;
		}
		if(g1==1&&g2==1){
			puts("YES");
			for(int i=1;i<=n;++i){
				pt(bel[i],i==n?'\n':' ');
			}
			return 0;
		}
	}
	puts("NO");
	return 0;
}