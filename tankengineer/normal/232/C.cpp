#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int N = 105;
vector<long long> f;
vector<pair<long long, int> > head[N], tail[N];

inline int min(const int &a, const int &b) {
	return a > b ? b : a;
}

int dist(const long long a, const long long b, const int n) {
	if (a == b) {
		return 0;
	}
	if (a == b - 1) {
		return 1;
	}
	if (a == 1) {
		for (int i = 0; i < (int)head[n].size(); ++i) {
			if (head[n][i].first == b) {
				return head[n][i].second;
			}
		}
	}
	if (b == f[n]) {
		for (int i = 0; i < (int)tail[n].size(); ++i) {
			if (tail[n][i].first == a) {
				return tail[n][i].second;
			}
		}
	}
	int ret;
	if (a > f[n - 1]) {
		ret = dist(a - f[n - 1], b - f[n - 1], n - 2);
	} else if (b <= f[n - 1]) {
		ret = min(dist(a, b, n - 1), min(dist(1, a, n - 1) + dist(b, f[n - 1], n - 1), dist(a, f[n - 1], n - 1) + dist(1, b, n - 1)) + 2);
	} else {
		ret = dist(1, b - f[n - 1], n - 2) + min(dist(1, a, n - 1), dist(a, f[n - 1], n - 1)) + 1;
	}
	if (a == 1) {
		head[n].push_back(make_pair(b, ret));
	}
	if (b == f[n]) {
		tail[n].push_back(make_pair(a, ret));
	}
	return ret;
}

int main() {
	f.push_back(1);
	f.push_back(2);
	while (f.back() < 10000000000000000ll) {
		f.push_back(f.back() + f[f.size() - 2]);
	}
	int t, n;
	scanf("%d%d", &t, &n);
	while (t--) {
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		if (a > b) {
			swap(a, b);
		}
		int m = min(lower_bound(f.begin(), f.end(), b) - f.begin() + 1, n);
		for (int i = 0; i <= m; ++i) {
			head[i].clear();
			tail[i].clear();
		}
		printf("%d\n", dist(a, b, m));
	}
	return 0;
}