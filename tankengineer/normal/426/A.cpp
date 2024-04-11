#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += a[i];
	}
	puts(sum <= s ? "YES" : "NO");
	return 0;
}