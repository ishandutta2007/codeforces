// author: xay5421
// created: Sun Nov 29 15:10:54 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
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
const int N=500005,INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,K,a[N],pre[N],suf[N],w[N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(K);
	rep(i,1,n)rd(a[i]);
	sort(a+1,a+1+n,[&](int k1,int k2){return k1>k2;});
	int tem=0,ind=0;
	per(i,n,1){
		suf[i]=suf[i+1]+a[i]*ind;
		if(++tem==K+1){
			tem=0;
			++ind;
		}
		w[i]=ind;
	}
	//rep(i,1,n)D(">>> %lld\n",suf[i]);
	int ans=~INFLL;
	int sum=0;
	rep(i,1,n){
		pre[i]=pre[i-1]+sum;
		sum+=a[i];
		ans=max(ans,pre[i]+suf[i+1]+w[i+1]*sum);
	}
	pt(ans,'\n');
	return 0;
}