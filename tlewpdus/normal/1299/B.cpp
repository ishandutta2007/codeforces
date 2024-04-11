#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
pll arr[100100];

ll dis(pll a, pll b) {
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld%lld",&arr[i].first,&arr[i].second);
	if (n%2) {
		puts("NO");
		return 0;
	}
	for (int i=0;i<n/2;i++) {
		if (arr[i].first+arr[n/2+i].first==arr[i+1].first+arr[(n/2+i+1)%n].first&&
				arr[i].second+arr[n/2+i].second==arr[i+1].second+arr[(n/2+i+1)%n].second);
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}