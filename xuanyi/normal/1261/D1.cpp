//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
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

const int N=200005,P=998244353;

int n,k,a[N],fac[N],inv[N];

int C(int a,int b){
	if(a<0||b<0||a-b<0)return 0;
	return 1ll*fac[a]*inv[b]%P*inv[a-b]%P;
}
int fpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;
	return res;
}
int ask(int i){
	if(i&1)return fpow(2,i-1);
	else return 1ll*(P+1>>1)*(fpow(2,i)-C(i,i/2))%P;
}
signed main(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;++i)fac[i]=1ll*fac[i-1]*i%P,inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	for(int i=2;i<N;++i)inv[i]=1ll*inv[i-1]*inv[i]%P;
	rd(n),rd(k);
	rep(i,1,n)rd(a[i]);
	int tot=0;
	rep(i,1,n)if(a[i]!=a[i%n+1])++tot;
	int ans=0;
	rep(i,0,tot)(ans+=1ll*C(tot,i)*fpow(k-2,tot-i)%P*ask(i)%P)%=P;
	ans=1ll*ans*fpow(k,n-tot)%P;
	pt((ans+P)%P,'\n');
	return 0;
}