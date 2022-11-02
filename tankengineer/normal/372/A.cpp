#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
vector<int> v;

bool check(int l) {
	if (l * 2 > n) {
		return false;
	}
	for (int i = 0; i < l; ++i) {
		if (v[i] * 2 > v[n - l + i]) {
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
	int r = (n >> 1) + 1, l = 0, m;
	while (l < r) {
		m = (l + r + 1) >> 1;
		if (check(m)) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	int ans = n - l;
	printf("%d\n", ans);
	return 0;
}