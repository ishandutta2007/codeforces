#include <cstdio>
#define max_loglogn 6
#define ll long long
#define INF 9223372036854775807ll
using namespace std;
struct matrix{
	ll a[2][2];
	inline matrix(){}
	inline matrix(ll p,ll q,ll x,ll y):a{{p,q},{x,y}}{}
	inline const ll*operator[](int k)const{
		return a[k];
	}
	inline void eqsqr(const matrix&x){
		a[0][0]=(INF/x[0][0]<x[0][0]||INF/x[1][0]<x[0][1])?INF:(x[0][0]*x[0][0]+x[1][0]*x[0][1]),
		a[0][1]=x[0][1]*x[0][0]+x[1][1]*x[0][1],
		a[1][0]=x[0][0]*x[1][0]+x[1][0]*x[1][1],
		a[1][1]=x[0][1]*x[1][0]+x[1][1]*x[1][1];
		a[0][0]<0&&(a[0][0]=INF);
	}
	inline void init_unit(){
		a[0][0]=1,
		a[0][1]=0,
		a[1][0]=0,
		a[1][1]=1;
	}
	inline void times(const matrix&x){
//		printf("$&a%lld %lld %lld %lld\n",a[0][0],a[0][1],a[1][0],a[1][1]);
//		printf("$&x%lld %lld %lld %lld\n",x[0][0],x[0][1],x[1][0],x[1][1]);
		matrix tmp(x[0][0]*a[0][0]+x[1][0]*a[0][1],x[0][1]*a[0][0]+x[1][1]*a[0][1],x[0][0]*a[1][0]+x[1][0]*a[1][1],x[0][1]*a[1][0]+x[1][1]*a[1][1]);
		a[0][0]=tmp[0][0],
		a[0][1]=tmp[0][1],
		a[1][0]=tmp[1][0],
		a[1][1]=tmp[1][1];
//		printf("$&%lld %lld %lld %lld\n",a[0][0],a[0][1],a[1][0],a[1][1]);
	}
	inline ll times00(const matrix&x)const{
		const ll tmp=(INF/x[0][0]<a[0][0]||INF/x[1][0]<a[0][1])?INF:x[0][0]*a[0][0]+x[1][0]*a[0][1];
//		if(tmp==INF||tmp<0)
//			printf("&%lld$%lld %lld %lld %lld\n",tmp,x[0][0],a[0][0],x[1][0],a[0][1]);
		return tmp<0?INF:tmp;
	}
};
matrix x;
matrix a[max_loglogn<<1|1];
void test(){
	ll n,m;
	int ans=0;
//	scanf("%lld%lld",&n,&m);
//	--m;
//	n=((n-2)/m+1)*m+1;
	scanf("%lld",&n),m=1;
	int k=0;
	for(a[0]=matrix(1,m,1,0); n>=a[k][0][0]; a[k].eqsqr(a[k-1]))
		++k;
//	printf("%d %lld %lld %lld %lld\n",k,a[k-1][0][0],a[k-1][0][1],a[k-1][1][0],a[k-1][1][1]);
	x.init_unit();
	for(; ~--k; x.times00(a[k])<=n&&(x.times(a[k]),ans|=1<<k));
//	printf("*%lld %lld %lld %lld %lld\n",x.times00(a[0]),x[0][0],x[0][1],x[1][0],x[1][1]);
	
	printf("%d\n",ans-1);
}
int main(){
//	int n;
//	scanf("%d",&n);
//	for(++n; --n; test());
	test();
	return 0;
}