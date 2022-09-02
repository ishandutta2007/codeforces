//by xay5421 2449670833@qq.com
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int P=1000000007;
int n;signed f[80][(1<<20)+5];char s[80];
signed main(){
	rd(n);scanf("%s",s+1); 
	rep(i,1,n){
		f[i][0]=1; 
		int x=0;
		rep(j,i,n){
			x=x*2+(s[j]&1);
			if(x>=20)break;
			if(x>0)
				rep(t,0,(1<<20)-1)
					(f[j+1][t|(1<<(x-1))]+=f[i][t])%=P;
		}
	}
	int ans=0;
	rep(i,1,n+1){
		for(int r=1;r<(1<<20);r=r*2+1){
			(ans+=f[i][r])%=P;
		}
	}
	pt(ans,'\n');
	return 0;
}