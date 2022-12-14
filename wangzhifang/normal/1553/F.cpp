#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 200000
#define m 300000
#define max_m 300000
#define blk1 300
#define blk2 300
ll a[max_m+1],b[max_m+1],c[max_m+1],d[max_m+1],e[max_m+1],f[max_m+1];
long long qry1(ci x){
	if(x<=blk1)
		return a[x];
	long long sum=0,ret=0;
	for(int i=m/x*x,j=m/blk1; i; i-=x){
		for(int now=i/blk1; j>now; --j)
			sum+=b[j];
		ret+=sum+c[i];
	}
	return ret;
}
long long qry2(ci x){
	long long ret=0;
	for(int i=1; i<=blk2; ++i)
		ret+=i*(x/i)*d[i];
	if(x>blk2){
		for(int i=1,now=x/blk2; i<now; ++i)
			ret+=e[i];
		for(int i=x; ret+=f[i],i%blk2; --i);
	}
	return ret;
}
void ins(ci x){
	for(int i=1; i<=blk1; ++i)
		a[i]+=x/i;
	++b[x/blk1];
	for(int i=x; ++c[i],i%blk1; --i);
	if(x<=blk2)
		++d[x];
	else{
		for(int i=x; i<=m; i+=x){
			e[i/blk2]+=x;
			f[i]+=x;
		}
	}
}
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	ll ans=0;
	printf("0 ");
	ins(x);
	long long sum=x;
	for(int i=2,x; i<=n; ++i){
		scanf("%d",&x);
		ans+=sum-qry1(x)*x+x*ll(i-1)-qry2(x);
		printf("%lld ",ans);
		ins(x),sum+=x;
	}
	return 0;
}