#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1<<30, ans2, i, x;
int main(){
	for(scanf("%lld",&n),i=0;i<n;i++){
		scanf("%lld",&x);
		long long cyc = max(0LL,x-i);
		long long w = ceil(cyc/(double)n);
		if(w*n+i<ans)ans = min(ans,w*n+i),ans2=i;
	}
	printf("%lld\n",ans2+1);
	getchar(); getchar();
}