// author: xay5421
// created: Tue Jan  5 22:49:31 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
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
const int N=1000005;
int T,n,a[N],p[N],d[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1,d[1]=1;
	rep(i,2,N-1){
		if(!ban[i])p[++*p]=i,d[i]=i;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			d[i*p[j]]=d[i]%p[j]==0?d[i]/p[j]:d[i]*p[j];
			if(i%p[j]==0)break;
		}
	}
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),a[i]=d[a[i]];
		sort(a+1,a+1+n);
		int res0=0;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&a[i]==a[j])++j;
			umax(res0,j-i);
			if(~(j-i)&1){
				rep(k,i,j-1)a[k]=1;
			}
		}
		sort(a+1,a+1+n);
		int res1=0;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&a[i]==a[j])++j;
			umax(res1,j-i);
		}
		int Q;
		rd(Q);
		while(Q--){
			LL w;
			rd(w);
			if(w==0)pt(res0,'\n');
			else pt(res1,'\n');
		}
	}
	return 0;
}