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
const int N=1000005,K=21;
int n,m,a[N],ans[N],lg[N];signed g[N][K];
int qry(int l,int r){
	int x=lg[r-l+1];
	int a=g[l][x],b=g[r-(1<<x)+1][x];
	return ::a[a]>::a[b]?g[l][x]:g[r-(1<<x)+1][x];
}
void add(int l,int r,int x){
	if(l<=r)ans[l]+=x,ans[r+1]-=x;
}
void solve(int l,int r,int lx,int rx,int len){
	if(l>r||lx>rx)return;
	int pos=qry(l,r),L=pos,R=pos+m-len,x=a[pos];
	if(x<=0)L=max(L,m-len+1),R=min(R,len);
	L=max(lx,L),R=min(rx,R);
	if(L>R)return;
	add(L,R,x);
	solve(l,pos-1,lx,L-1,len);
	solve(pos+1,r,R+1,rx,len);
}
signed main(){
	rd(n),rd(m);
	for(int i=2;i<N;++i)lg[i]=lg[i>>1]+1;
	rep(_,1,n){
		int l;rd(l);
		rep(i,1,l)rd(a[i]),g[i][0]=i;
		for(int j=1;j<K;++j)
			for(int i=1;i+(1<<j)-1<=l;++i){
				int a=::a[g[i][j-1]],b=::a[g[i+(1<<(j-1))][j-1]];
				if(a>b){
					g[i][j]=g[i][j-1];
				}else{
					g[i][j]=g[i+(1<<(j-1))][j-1];
				}
			}
		solve(1,l,1,m,l);
	}
	for(int i=1;i<=m;++i)ans[i]+=ans[i-1];
	for(int i=1;i<=m;++i)pt(ans[i],' ');
	return 0;
}