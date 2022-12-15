#include <bits/stdc++.h>
using namespace std;

const int MN = 5e5+5;
typedef long long ll;
ll N, M, K, lo, hi, i, cnt;

int main(){
	scanf("%lld%lld%lld",&N,&M,&K);
	lo = 1; hi = N*M;
	while(lo < hi){
		ll m=lo+hi>>1; cnt=0;
		for(i=1;i<=N;i++)
			cnt+=min(M,m/i);
		if(cnt>=K) hi=m;
		else lo=m+1;
	}
	printf("%lld\n",lo);
	getchar(); getchar();
}