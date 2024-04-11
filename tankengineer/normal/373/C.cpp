#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
vector<int> v;

bool check(int t) {
	if (t * 2 > v.size()) {
		return false;
	}
	for (int i = 0; i < t; ++i) {
		if (v[i] * 2 > v[n - t + i]) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int left = 0, right = n / 2 + 1, mid;
	while (left < right) {
		mid = left + right + 1 >> 1;
		if (check(mid)) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	printf("%d\n", n - left);
	return 0;
}