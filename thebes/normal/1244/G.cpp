#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e6+6;
ll N, K, M, i, j, rem, cur;
set<ll> ok; vector<int> ans;

int main(){
	scanf("%lld%lld",&N,&K);
	M = K;
	rem = N*(N+1)/2;
	if(rem>K){
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=N;i++) ok.insert(i);
	for(i=1;i<=N;i++){
		rem -= i;
		ll lim = M-rem;
		auto it=ok.upper_bound(lim); it--;
		M -= max(i,*it);
		ans.push_back(*it);
		ok.erase(it);
	}
	printf("%lld\n",K-M);
	for(auto v : ans)
		printf("%d ",v);
	printf("\n");
	for(i=1;i<=N;i++)
		printf("%d ",i);
	printf("\n");
	return 0;
}