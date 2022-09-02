//by xay5421 2449670833@qq.com
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
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
const int P=1000000007,N=1000005,M=21;
int T,n,r,f[N][M],p[N],d[N];bool vis[N];
void pre(){
	vis[0]=vis[1]=1;
	for(int i=2;i<N;++i){
		if(!vis[i])p[++*p]=i,d[i]=i;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			vis[i*p[j]]=1;
			d[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
signed main(){
	pre();
	rd(T);
	f[0][0]=1;for(int i=1;i<M;++i)f[0][i]=2;
	for(int i=1;i<N;++i){
		f[i][0]=1;
		for(int j=1;j<M;++j)f[i][j]=(f[i-1][j]+f[i][j-1])%P;
	}
	while(T--){
		rd(r),rd(n);int ans=1;
		while(n>1){
			int t=d[n],k=0;
			while(n%t==0)n/=t,++k;
			ans=1ll*ans*f[r][k]%P;
		}
		pt(ans,'\n');
	}
	return 0;
}