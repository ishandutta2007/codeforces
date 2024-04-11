#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long lli;

const lli mod=1e9+7;

int k,pa,pb;
lli cache[1001][1001];
lli pow(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
lli inv(lli val) {
	return pow(val,mod-2);
}
lli DP(int a,int b) {
	if(a+b>=k) {
		return (a+b+pa*inv(pb))%mod;
	}
	lli &ret=cache[a][b];
	if(ret!=-1) return ret;

	return ret=(pa*DP(a+1,b)+pb*DP(a,a+b))%mod*inv(pa+pb)%mod;
}
int main() {
	scanf("%d%d%d",&k,&pa,&pb);
	memset(cache,-1,sizeof(cache));
	printf("%lld\n",DP(1,0));
	return 0;
}