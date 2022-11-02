#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int has[13];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		has[a]+=1;
	}
	ll ans = (ll) n*(n-1)/2;
	for (int i=0;i<=10;i++) ans-=(ll) has[i]*(has[i]-1)/2;
	printf("%lld\n",ans);

	return 0;
}