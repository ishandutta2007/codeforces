#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
vector<ll> lis[800100];

int main() {
	scanf("%d",&n);
	const int bia = 200100;
	for (int i=0;i<n;i++) {
		int b;
		scanf("%d",&b);
		lis[b-i+bia].push_back(b);
	}
	ll maxi = 0;
	for (int i=0;i<800100;i++) {
		ll sum = 0;
		for (ll &j : lis[i]) sum += j;
		maxi = max(maxi,sum);
	}
	printf("%lld\n",maxi);

	return 0;
}