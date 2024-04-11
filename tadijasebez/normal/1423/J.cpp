#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
void ckadd(int&x,int y){x+=y;if(x>=mod)x-=mod;}
void cksub(int&x,int y){x-=y;if(x<0)x+=mod;}
int main(){
	int t;scanf("%i",&t);
	while(t--){
		ll m;scanf("%lld",&m);
		int ans=(m/2+1)%mod;
		ckadd(ans,m/4%mod*((m/4+1)%mod)%mod);
		if((m/2)%2==0)cksub(ans,m/4%mod);
		printf("%i\n",ans);
	}
	return 0;
}