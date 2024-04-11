#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

int n, k;

long long l;

int main() {
	cin >> n >> l >> k;
	vector<pair<pair<int, int>, long long> > evts;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		evts.push_back(make_pair(make_pair(a, i), 1));
	}
	sort(evts.begin(), evts.end());
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			int end = i * n + evts[j].first.second;
			if (end < l) {
				(ans += (long long)evts[j].second * (((l - end + n - 1) / n) % MOD) % MOD) %= MOD;
			}
			(sum += evts[j].second) %= MOD;
		}
		for (int j = n - 1; j >= 0; --j) {
			int k = j, delta = 0;
			while (k >= 0 && evts[k].first.first == evts[j].first.first) {
				(delta += evts[k].second) %= MOD;
				evts[k].second = sum;
				--k;
			}
			sum = (sum - delta + MOD) % MOD;
			j = k + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}