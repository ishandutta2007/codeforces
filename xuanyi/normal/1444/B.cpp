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
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005,P=998244353;
int n,a[N],fac[N],ifac[N],inv[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
signed main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	rd(n);
	rep(i,1,n*2)rd(a[i]);
	sort(a+1,a+1+n*2);
	int sum=0;
	rep(i,1,n)a[i]%=P,(sum+=P-a[i])%=P;
	rep(i,n+1,n*2)a[i]%=P,(sum+=a[i])%=P;
	pt(1LL*sum*C(n*2,n)%P,'\n');
	return 0;
}