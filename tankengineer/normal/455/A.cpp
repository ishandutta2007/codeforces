#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	vector<pair<int, long long> > p;
	for (int i = 0; i < (int)v.size(); ++i) {
		int j = i;
		while (j < (int)v.size() && v[j] == v[i]) {
			++j;
		}
		p.push_back(make_pair(v[i], (long long)v[i] * (j - i)));
		i = j - 1;
	}
	vector<long long> dp[2];	
	dp[0].resize(p.size() + 1),
	dp[1].resize(p.size() + 1);
	dp[0][0] = 0, dp[1][0] = 0;
	for (int i = 0; i < (int)p.size(); ++i) {
		dp[0][i + 1] = max(dp[1][i], dp[0][i]);
		dp[1][i + 1] = dp[0][i] + p[i].second;
		if (i > 0 && p[i].first > p[i - 1].first + 1) {
			dp[1][i + 1] = max(dp[1][i + 1], dp[1][i] + p[i].second);
		}
	}
	cout << max(dp[0][p.size()], dp[1][p.size()]) << endl;
	return 0;
}