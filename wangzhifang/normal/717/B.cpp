#include <cstdio>
#include <algorithm>
#define cs const
#define inf 2147483647
using namespace std;
typedef long long ll;
typedef cs ll& cll;
typedef cs int& ci;
ll c0,c1,n;
ll gcd(cll a,cll b){
	return b?gcd(b,a%b):a;
}
ll lls[31];
ll comb(cll a,ci b){
    ll s=1,x,g;
    for(int i=0; ++i<=b; lls[i]=i);
    for(int i=-1; ++i<b; ){
    	x=a+b-i;
    	for(ll j=0; ++j<=b; ){
    		g=gcd(lls[j],x);
    		x/=g;
    		lls[j]/=g;
		}
		if(x>inf/s)
			return inf;
		s*=x;
	}
    return s;
}
bool check(cll x){
	ll tmp=x/c0+x/c1+1;
	if(tmp>n)
    	return 1;
    for(int i=0; ++i<=26; ){
		for(ll j=i-1; (++j)*c0+i*c1<=x; )
			if((tmp+=comb(j,i))>n)
				return 1;
		for(ll j=i; (++j)*c1+i*c0<=x; )
			if((tmp+=comb(j,i))>n)
				return 1;
	}
	return 0;
}
void work(cll x,ll&tmp,ll&ans){
	tmp=x/c0+x/c1+1;
	ans=((x/c0)*(x/c0+1)*c0+(x/c1)*(x/c1+1)*c1)>>1;
	ll c;
	for(int i=0; ++i<=26; ){
		for(ll j=i-1; (++j)*c0+i*c1<=x; ans+=c*(j*c0+i*c1))
			tmp+=(c=comb(j,i));
		for(ll j=i; (++j)*c1+i*c0<=x; ans+=c*(j*c1+i*c0))
			tmp+=(c=comb(j,i));
	}
}
int main(){
	scanf("%lld%lld%lld",&n,&c0,&c1);
	--n,c0>c1&&(swap(c0,c1),1);
	if(!c0){
		printf("%lld\n",n*c1);
		return 0;
	}
	ll l=0,r=c1*26,mid;
    while(l<=r){
        mid=(l+r)>>1;    
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    ll c,s;
    work(l-1,c,s);
    s+=(n-c)*l+n*(c0+c1);
    printf("%lld\n",s);
    return 0;
}