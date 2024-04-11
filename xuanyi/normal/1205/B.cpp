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
const int N=200105;
int n,res,a[N],vis[N],f[1005][1005],g[1005][1005],tot[1005];
signed main(){
	for(int i=0;i<=1000;++i)for(int j=0;j<=1000;++j)f[i][j]=g[i][j]=(int)1e15;
	int ans=1e15;
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		rep(j,0,62)if(a[i]>>j&1)if(++tot[j]==3){
			pt(3,'\n');return 0;
		}
	}
	int m=n;n=0;
	rep(i,1,m)if(a[i])a[++n]=a[i];
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)if(a[i]&a[j])g[i][j]=f[i][j]=1;
	rep(k,1,n){
		rep(i,1,k-1)rep(j,1,k-1)if(i!=j&&i!=k&&j!=k){
			ans=min(ans,g[i][k]+g[k][j]+f[i][j]);
		}
		rep(i,1,n)rep(j,1,n)if(i!=j&&i!=k&&j!=k)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	if(ans==1e15)puts("-1");else pt(ans,'\n');
	return 0;
}