#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
ll psa[MN], n, x, y, i, mx=-1LL<<60, mn=1LL<<60, ans=-1LL<<60;
ll sum(ll x,ll y){return((x%2)?1:-1)*(y-psa[x-1]);}

int main(){
	scanf("%lld%lld",&n,&y);
	for(i=1;i<n;i++){
		x=y; scanf("%lld",&y);
		psa[i]=((i%2)?1:-1)*abs(y-x);
		psa[i]+=psa[i-1];
	}
	for(i=n-1;i>=1;i--){
		mx = max(mx, psa[i]);
		mn = min(mn, psa[i]);
		ans = max(ans,max(sum(i,mx),sum(i,mn)));
	}
	printf("%lld\n",ans);
	return 0;
}