#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 1000000007;
ll N, K;

ll f(ll n){
	ll ret = n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ret = ret / i * (i-1);
		}
		while(n%i==0) n = n / i;
	}
	if(n>1){
		ret = ret / n * (n-1);
	}
	return ret;
}

int main(){
	scanf("%lld%lld",&N,&K);
	K = (K+1)/2;
	while(K > 0){
		ll n = f(N);
		if(n == N){
			printf("%lld\n", n % MOD);
			return 0;
		}
		N = n;
		K--;
	}
	printf("%lld\n", N%MOD);
	return 0;
}