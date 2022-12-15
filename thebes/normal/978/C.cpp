#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll psa[200005], N, M, i, x, y;

int main(){
	for(scanf("%lld%lld",&N,&M),i=1;i<=N;i++)
		scanf("%lld",&psa[i]),psa[i]+=psa[i-1];
	for(i=1;i<=M;i++){
		scanf("%lld",&x);
		y = lower_bound(psa+1,psa+N+1,x)-psa;
		printf("%lld %lld\n",y,x-psa[y-1]);
	}
	return 0;
}