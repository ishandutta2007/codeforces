#include <cstdio>
#include <algorithm>
using namespace std;
#define INF ll(1e18)
typedef long long ll;
int main(){
	ll n,r,s,t,d,x=0,y=INF,m,u;
	scanf("%lld%lld%lld%lld%lld",&n,&r,&s,&t,&d);
	for(int i=1; i<=n; ++i){
		scanf("%lld",&u);
		m=min(r*(u+2),r+s);
		if(i<n){
			ll ty=x+m+2*d;
			x=min(x+r*u+t,min(y+m,ty));
			y=ty;
		}
		else{
			ll ty=x+m+2*d;
			x=min(min(x+r*u+t,y+m),min(ty,y+r*u+t-d));
			y=ty;
		}
	}
	printf("%lld\n",x+d*(n-1));
	return 0;
}