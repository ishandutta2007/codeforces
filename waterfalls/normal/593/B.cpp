#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x1,x2;
pair<ll,ll> line[100013];

int main() {
	scanf("%d%lld%lld",&n,&x1,&x2);
	for (int i=0;i<n;i++) {
		ll k,b;
		scanf("%lld%lld",&k,&b);
		line[i].first = k*x1+b;
		line[i].second = k*x2+b;
	}
	sort(line,line+n);
	ll far = -1e18;
	int j = 0;
	for (int i=0;i<n;i++) {
		while (line[j].first<line[i].first) far = max(far,line[j++].second);
		if (line[i].second<far) return printf("Yes\n"), 0;
	}
	printf("No\n");

	return 0;
}