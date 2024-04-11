#include <cstdio>
#define max_n 200000
#define mod 998244353
#define ll long long
#define cs const
using namespace std;
struct matrix{
	ll a,b,c,d;
	matrix(){}
	matrix(int k):a(k),b(0),c(0),d(k){}
	matrix(ll u,ll v,ll p,ll q):a(u%mod),b(v%mod),c(p%mod),d(q%mod){}
	friend matrix operator*(cs matrix&x,cs matrix&y){
		return matrix(x.a*y.a+x.b*y.c,x.a*y.b+x.b*y.d,x.c*y.a+x.d*y.c,x.c*y.b+x.d*y.d);
	}
};
template<typename T>T quickpow(T x,long long k){
	T ret=1;
	for(; k; k>>=1,x=x*x)
		(k&1)&&(ret=ret*x,1);
	return ret;
}
int a[max_n+1];
int main(){
	int n;
	long long ans,k;
	scanf("%d%lld",&n,&k);
	matrix u(0,k-1,1,k-2),tmp;
	for(int i=0; ++i<=n; scanf("%d",a+i));
	int l,r=-1;
	while((r+=2)<=n&&a[r]==-1);
	if(r>n){
		tmp=quickpow(u,(r>>1)-1);
		ans=(tmp.a+tmp.b+(k-1)*(tmp.c+tmp.d))%mod;
	}
	else{
		tmp=quickpow(u,r>>1);
		ans=tmp.a+tmp.b;//also=tmp.c+tmp.d
		while(1){
			while((r+=2)<=n&&a[r]!=-1)
				if(a[r]==a[r-2]){
					puts("0");
					return 0;
				}
			if(r>n)
				break;
			l=r;
			while((r+=2)<=n&&a[r]==-1);
			if(r>n){
				tmp=quickpow(u,(r-l>>1)-1);
				ans=ans*(tmp.b+(k-1)*tmp.d%mod)%mod;
				break;
			}
			tmp=quickpow(u,r-l>>1);
			ans=ans*(a[r]==a[l-2]?tmp.b:tmp.d)%mod;
		}
	}
	if(n==1){
		printf("%lld\n",ans);
		return 0;
	}
	r=0;
	while((r+=2)<=n&&a[r]==-1);
	if(r>n){
		tmp=quickpow(u,(r>>1)-2);
		ans=ans*(tmp.a+tmp.b+(k-1)*(tmp.c+tmp.d)%mod)%mod;
	}
	else{
		tmp=quickpow(u,(r>>1)-1);
		ans=ans*(tmp.a+tmp.b)%mod;//also=tmp.c+tmp.d
		while(1){
			while((r+=2)<=n&&a[r]!=-1)
				if(a[r]==a[r-2]){
					puts("0");
					return 0;
				}
			if(r>n)
				break;
			l=r;
			while((r+=2)<=n&&a[r]==-1);
			if(r>n){
				tmp=quickpow(u,(r-l>>1)-1);
				ans=ans*(tmp.b+(k-1)*tmp.d%mod)%mod;
				break;
			}
			tmp=quickpow(u,r-l>>1);
			ans=ans*(a[r]==a[l-2]?tmp.b:tmp.d)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}