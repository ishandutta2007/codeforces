//by xay5421 2449670833@qq.com
#include<cstdio>
#include<cstring>
#define int long long
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;typedef unsigned long long ull;
template<typename T>inline void rd(T&x){int f=0,c;while(c=getchar(),c<48||57<c)f^=!(c^45);x=(c&15);while(c=getchar(),47<c&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=55;
int n,f[N][N][N][N];char s[N][N];
signed main(){
	memset(f,63,sizeof(f));
	rd(n);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(L,1,n){
		rep(R,1,n){
			rep(i,1,n-L+1){
				rep(j,1,n-R+1){
					int a=i+L-1,b=j+R-1;
					f[i][j][a][b]=min(f[i][j][a][b],max(L,R));
					if(L==1&&R==1){
						if(s[i][j]=='.')f[i][j][a][b]=0;
					}
					rep(k,1,i-1)f[k][j][a][b]=min(f[k][j][a][b],f[i][j][a][b]+f[k][j][i-1][b]); 
					rep(k,a+1,n)f[i][j][k][b]=min(f[i][j][k][b],f[i][j][a][b]+f[a+1][j][k][b]);
					rep(k,1,j-1)f[i][k][a][b]=min(f[i][k][a][b],f[i][j][a][b]+f[i][k][a][j-1]);
					rep(k,b+1,n)f[i][j][a][k]=min(f[i][j][a][k],f[i][j][a][b]+f[i][j+1][a][k]);
				}
			}
		}
	}
	pt(f[1][1][n][n],'\n');
	return 0;
}