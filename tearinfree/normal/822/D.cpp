#include <cstdio>
#include <algorithm>
#include <utility>

typedef long long lli;
const lli mod=1e9+7;
lli tt;
int ll,rr;
lli val[5000001];
int mval[5000001];
bool prime[5000001];

int main() {
	scanf("%lld %d %d",&tt,&ll,&rr);
	for(int i=2;i<=2240;i++) {
		if(!prime[i]) {
			val[i]=(long long)i*(i-1)/2%mod;
			for(int j=i*i;j<=5000000;j+=i) {
				prime[j]=true;
				if(mval[j]==0) mval[j]=i;
			}
		}
		else {
			val[i]=(val[mval[i]]*(i/mval[i])%mod+val[i/mval[i]])%mod;
		}
	}
	for(int i=2241;i<=5000000;i++) {
		if(!prime[i]) val[i]=(long long)i*(i-1)/2%mod;
		else {
			val[i]=(val[mval[i]]*(i/mval[i])%mod+val[i/mval[i]])%mod;
		}
	}
	
	lli tp=1,res=0;
	for(int i=ll;i<=rr;i++) {
		res=(res+tp*val[i])%mod;
		tp=tp*tt%mod;
	}
	printf("%lld\n",res);
	
	return 0;	
}