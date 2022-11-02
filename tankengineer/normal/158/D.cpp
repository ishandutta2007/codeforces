#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 2000000000;

int main() {
	int n;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		v.push_back(t1);		
	}
	int ans = -INF;
	for (int _ = 3; _ <= n; ++_) {
		if (n % _ != 0) {
			continue;
		}
		int i = n / _;
		vector<int> sum;
		for (int j = 0; j < i; ++j) {
			sum.push_back(0);
		}
		for (int j = 0; j < n; ++j) {
			sum[j % i] += v[j];
		}
		for (int j = 0; j < i; ++j) {
			ans = max(ans, sum[j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}