#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a,b,c,d;

int main() {
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	ll ans = 0;
	for (int i=1;i<=n;i++) {
		int j = i+b-c;
		int k = j+a-d;
		int l = k+c-b;
		if (j<1 || k<1 || l<1 || j>n || k>n || l>n) continue;
		ans+=n;
	}
	printf("%lld\n",ans);

	return 0;
}