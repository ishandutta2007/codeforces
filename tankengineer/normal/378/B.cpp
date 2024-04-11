#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000;
int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", a + i, b + i);
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	int k = n / 2;
	string ans;
	for (int i = 0; i < n; ++i) {
		if (i < k || lower_bound(v.begin(), v.end(), a[i]) - v.begin() < n) {
			ans += '1';
		} else {
			ans += '0';
		}
	}
	printf("%s\n", ans.c_str());
	ans = "";
	for (int i = 0; i < n; ++i) {
		if (i < k || lower_bound(v.begin(), v.end(), b[i]) - v.begin() < n) {
			ans += '1';
		} else {
			ans += '0';
		}
	}
	printf("%s\n", ans.c_str());
	return 0;
}