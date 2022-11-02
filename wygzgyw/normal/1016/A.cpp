#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a,b;
ll f(ll x) {
	return x/m;
}
int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a);
		printf("%lld ",f(b+a)-f(b));
		b+=a;
	}
	printf("\n");
	return 0;
}