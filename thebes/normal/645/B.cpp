#include <bits/stdc++.h>
using namespace std;

long long N, K, ans, i;

int main(){
	scanf("%lld%lld",&N,&K);
	for(i=1;i<=min(K,N/2);i++)
		ans += 2*(N-2*i)+1;
	printf("%lld\n",ans);
	return 0;
}