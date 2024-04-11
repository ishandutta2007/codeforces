#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main() {
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++) {
		scanf("%lld",&n);
		ll res = n*(n+1)/2;
		int on = 0;
		while ((1<<(on+1))<=n) on+=1;
		res-=2*((1LL<<(on+1))-1);
		printf("%lld\n",res);
	}

	return 0;
}