// author: xay5421
// created: Sun Dec  6 23:04:01 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
//#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005,K=20;
int T,n,a[N],id[N],ans[N],f[N][K],lg[N],ind,bin[N],b[N];
int ask(int l,int r){
	int x=lg[r-l+1];
	return min(f[l][x],f[r-(1<<x)+1][x]);
}
bool chk(int mid){
	++ind;
	rep(i,1,n-mid+1){
		b[i]=ask(i,i+mid-1);
		if(b[i]>=1&&b[i]<=n-mid+1&&bin[b[i]]!=ind){
			bin[b[i]]=ind;
		}else return 0;
	}
	return 1;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),id[i]=i,f[i][0]=a[i];
		rep(j,1,K-1)rep(i,1,n-(1<<j)+1){
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
		sort(id+1,id+1+n,[&](int k1,int k2){return a[k1]<a[k2];});
		fill(ans+1,ans+1+n,0);
		ans[1]=1;
		rep(i,1,n)if(a[id[i]]!=i)ans[1]=0;
		int l=2,r=n,res=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(mid))r=mid-1,res=mid;else l=mid+1;
		}
		rep(i,res,n)ans[i]=1;
		rep(i,1,n)putchar(ans[i]+'0');
		puts("");
	}
	return 0;
}