#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;

const int N = 100000;

std::vector<pii>v;

int a[N + 5], c[N + 5], n;

int main() {
	ll ans = 0; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d", &a[i], &c[i]);
		v.push_back(std::make_pair(a[i], 0));
		v.push_back(std::make_pair(a[i] + c[i], 1));
		ans -= a[i];
	}
	std::sort(v.begin(), v.end());
	
	int c0 = 0, c1 = 0;
	for(int i=(int)v.size()-1;i>=0;i--) {
//		printf("%d %d\n", v[i].first, v[i].second);
		if( v[i].second == 1 ) {
			if( c0 ) c0--; else c1++, ans += v[i].first;
		} else {
			if( i == 0 || c1 > 1 ) c1--;
			else c0++, ans += v[i].first;
		}
	}
	printf("%lld\n", ans);
}