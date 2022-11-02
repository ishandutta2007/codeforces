#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool check(vector<int> &a) {
	for (int i = 0; i + 1 < (int)a.size(); ++i) {
		int l = a[i], r = a[i + 1];
		if (l > r) {
			swap(l, r);
		}
		if (r - l >= 2) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (check(a)) {
			puts("NO");
			return 0;
		}
		int j = 0;
		for (int k = 0; k < (int)a.size(); ++k) {
			if (a[k] > a[j]) {
				j = k;
			}
		}
		b.push_back(a[j]);
		a.erase(a.begin() + j);
	}
	if (check(b)) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}