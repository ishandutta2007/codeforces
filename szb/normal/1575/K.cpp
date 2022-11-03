#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod=1000000007;
LL n,m,k,r,c,a1,a2,b1,b2,num;

LL pw(LL x,LL k){
	if (!k) return 1;
	LL tmp=pw(x*x%mod,k>>1);
	return k&1?tmp*x%mod:tmp;
}

void solve(LL x,LL y,LL a,LL b){
	if (a*2<=x||b*2<=y){
		num+=x*y-a*b;
		return;
	}
	LL nx=a*2-x,ny=b*2-y;
	num+=x*y-a*b*2+nx*ny;
	solve(a,b,nx,ny);
}

int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&r,&c);
	scanf("%lld%lld%lld%lld",&a1,&a2,&b1,&b2);
	if (a1==b1&&a2==b2){
		num=n*m;
	}
	else{
		LL c1=min(a1,b1),c2=max(a1,b1)+r-1;
		LL d1=min(a2,b2),d2=max(a2,b2)+c-1;
		LL cc=c2-c1+1,dd=d2-d1+1;
		num=n*m-cc*dd;
		solve(cc,dd,r,c);
	}
	printf("%lld\n",pw(k,num));
	
	return 0;
}