#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		bool ans = true, used = false, ended = false;
		int delta = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) {
				if (!used) {
					used = true;
					delta = b[i] - a[i];
					if (delta < 0) {
						ans = false;
					}
				} else if (!ended) {
					if (a[i] + delta != b[i]) {
						ans = false;
					}
				} else {
					ans = false;
				}
			} else {
				if (used && !ended) {
					ended = true;
				}
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}