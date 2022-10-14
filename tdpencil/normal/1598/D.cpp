#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		map<int, int> cnt1;
		map<int, int> cnt2;
		
		long long r = 1LL * n * (n - 1) * (n - 2) / 6;
		vector<pair<int, int>> num(n);
		for(int i = 0; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			cnt1[a]++;
			cnt2[b]++;
			num[i].first = a;
			num[i].second = b;
		}
		
		for(int i = 0; i < n; i++) {
			r -= (cnt1[num[i].first] - 1) * 1LL * (cnt2[num[i].second] - 1);
		}
		printf("%lld\n", r);
		
	}
}