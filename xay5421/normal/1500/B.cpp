// author: xay5421
// created: Sat Mar 13 17:13:29 2021
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
const int N=1000005;
int n,m,K,a[N],b[N],w1[N],pos[N];
void exgcd(int a,int b,int&x,int&y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(K);
	rep(i,1,n)rd(a[i]);
	rep(i,1,m)rd(b[i]);
	if(n>m)swap(n,m),swap(a,b);
	rep(i,1,m)pos[b[i]]=i;
	LL g=__gcd(n,m);
	LL lcm=n*m/g,tem=lcm;
	rep(i,1,n){
		int p=pos[a[i]];
		if(p&&p%g==i%g){
			--tem;
		}
	}
	LL ans=K/tem*lcm;
	K%=tem;
	if(K==0){
		K+=tem;
		ans-=lcm;
	}
	assert(K);
	auto calc=[&](int k){
		int x,y;
		exgcd(n,m,x,y);
		x=(x%m+m)%m*(k/g)%m;
		return x;
	};
	rep(i,1,n){
		int p=pos[a[i]];
		if(p&&p%g==i%g){
			w1[i]=(1LL*n*calc(((p-i)%m+m)%m)+i-1)%lcm+1;
		}else{
			w1[i]=1e18;
		}
	}
	auto sol=[&](LL mid){
		LL cur=0;
		rep(i,1,n){
			if(i<=mid)cur+=((mid-i)/n+1)-(w1[i]<=mid);
		}
		return cur;
	};
	LL l=0,r=lcm,res=0;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(sol(mid)>=K)res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans+res);
	return 0;
}