#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
typedef long long lli;

lli mod,arr[2000000];
lli power(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
lli inv(lli val) {
	return power(val,mod-2);
}
int main() {
	lli a,b,x;
	scanf("%lld%lld%lld%lld",&a,&b,&mod,&x);
	
	lli v1=x%((mod-1)*mod)/mod,v2=b,iv=inv(a),ran=x%((mod-1)*mod)%mod,ans=0;

	for(int i=0;i<v1;i++) v2=(v2*iv)%mod;

	lli val=1;
	for(int i=1;i<=x && i<mod; i++) {
		val = i*power(a,i)%mod;
		arr[val]++;
		if(i<=ran && val == v2) ans++;
	}

	lli v3=x/((mod-1)*mod);
	for(int t=0;t<mod-1;t++) {
		ans += arr[b] * v3;
		if(t<v1) ans += arr[b];
		b = (b*iv)%mod;
	}
	printf("%lld\n",ans);

	return 0;
}