//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=2005,P=1000000007;

int n,m,f[2][N][N],sum[N][N];char s[N][N];

int getsum(int a,int b,int c,int d){
	if(a>c||b>d)return 0;
	return sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}

int getf0(int a,int b,int c,int d){
	if(a>c||b>d)return 0;
	return f[0][c][d]-f[0][c][b-1]-f[0][a-1][d]+f[0][a-1][b-1];
}

int getf1(int a,int b,int c,int d){
	if(a>c||b>d)return 0;
	return f[1][c][d]-f[1][c][b-1]-f[1][a-1][d]+f[1][a-1][b-1];
}

signed main(){
	rd(n),rd(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	if(s[n][m]=='R'){puts("0");return 0;}
	if(n==1&&m==1){
		puts("1");
		return 0;
	}
	rep(i,1,n)rep(j,1,m)sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(s[i][j]=='R');
	f[0][1][1]=1;
	f[1][1][1]=1;
	rep(i,1,n)rep(j,1,m){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(getsum(mid+1,j,n,j)<=n-i)ans=mid,r=mid-1;
			else l=mid+1;
		}
		(f[1][i][j]+=getf0(ans,j,i-1,j))%=P;
//		debug("%lld %lld %lld %lld\n",i,j,ans,j);
		l=1,r=j,ans=j;
		while(l<=r){
			int mid=(l+r)>>1;
			if(getsum(i,mid+1,i,m)<=m-j)ans=mid,r=mid-1;
			else l=mid+1;
		}
		(f[0][i][j]+=getf1(i,ans,i,j-1))%=P; 
//		debug("%lld %lld %lld %lld\n",i,j,i,ans);
//		debug("f[0][%lld][%lld]=%lld\n",i,j,f[0][i][j]);
//		debug("f[1][%lld][%lld]=%lld\n",i,j,f[1][i][j]);
		(f[0][i][j]+=f[0][i][j-1]+f[0][i-1][j]-f[0][i-1][j-1])%=P;
		(f[1][i][j]+=f[1][i][j-1]+f[1][i-1][j]-f[1][i-1][j-1])%=P;
	}
	pt(((getf0(n,m,n,m)+getf1(n,m,n,m))%P+P)%P,'\n');
	return 0;
}