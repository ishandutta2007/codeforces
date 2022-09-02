#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,a[2][N],b[2][N],sum[N],v[N];
LL ans;
int sgn(int x){return x<0?-1:x>0?1:0;}
LL deal(int l,int r,int a[2][N],int b[2][N],int x0,int x1,int rem){ //  rem
	LL ret=0;
	if(x0||x1)ret-=l-1;
	rep(i,l,r){
		if(a[0][i])ret-=i,++x0;
		if(a[1][i])ret-=i,++x1;
		if(i<r||sum[r]==0){
			if(b[0][i]){
				ret+=i;
				if(x0)--x0;else --x1,++ret;
			}
			if(b[1][i]){
				ret+=i;
				if(x1)--x1;else --x0,++ret;
			}
		}else{ // i==r&&sum[j]!=0
			ret+=i;
			if(rem==0){
				if(x1)--x1;else --x0,++ret;
			}else{
				if(x0)--x0;else --x1,++ret;
			}
			return ret;
		}
	}
	return ret;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	int dt=0;
	rep(i,0,1)rep(j,1,n)rd(a[i][j]),v[j]+=a[i][j],dt+=a[i][j];
	rep(i,0,1)rep(j,1,n)rd(b[i][j]),v[j]-=b[i][j],dt-=b[i][j];
	if(dt!=0)puts("-1"),exit(0);
	rep(i,1,n)sum[i]=sum[i-1]+v[i];
	LL dp[3]={INFLL,INFLL,0};
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(sum[i-1]){
			while(j<=n&&sgn(sum[j])==sgn(sum[i-1]))++j;
		}else{
			while(j<=n&&sgn(sum[j])==sgn(sum[i]))++j;
		}
		DD(i,j);
		if(sum[i]==0&&sum[i-1]==0){
			rep(k,i,j-1){
				dp[2]+=(a[0][k]^b[0][k])!=(b[1][k]^b[1][k]);
			}
			--j;
			continue;
		}
		LL ndp[3]={INFLL,INFLL,INFLL};
		rep(T,0,2)if(dp[T]!=INFLL){
			if(sum[j]==0){
				ndp[2]=min(ndp[2],dp[T]+deal(i,j,sum[j-1]>0?a:b,sum[j-1]>0?b:a,T==0?1:0,T==1?1:0,2));
			}else{
				ndp[0]=min(ndp[0],dp[T]+deal(i,j,sum[j-1]>0?a:b,sum[j-1]>0?b:a,T==0?1:0,T==1?1:0,0));
				ndp[1]=min(ndp[1],dp[T]+deal(i,j,sum[j-1]>0?a:b,sum[j-1]>0?b:a,T==0?1:0,T==1?1:0,1));
			}
		}
		copy(ndp,ndp+3,dp);
	}
	printf("%lld\n",*min_element(dp,dp+3));
	return 0;
}