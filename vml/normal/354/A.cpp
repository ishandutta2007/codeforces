#pragma comment(linker, "/STACK:16777216")

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int inf = 2000000000;

int main() {
	int n, l, r, ql, qr;
	scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
	vector <int> w(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	vector <int> prefix(n);
	prefix[0] = w[0] * l;
	for (int i = 1; i < n; i++) {
		prefix[i] += prefix[i - 1] + w[i] * l;
	}
	vector <int> suffix(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		suffix[i] += suffix[i + 1] + w[i] * r;
	}
	int ans = min(suffix[0] + qr * (n - 1), prefix[n - 1] + ql * (n - 1));
	for (int i = 0; i < n - 1; i++) {
		int result = prefix[i] + suffix[i + 1];
		if (abs(n - 2 * i - 2) > 1) {
			if (i < n - i - 2) {
				result += qr * (n - 2 * i - 3);
			} else {
				result += ql * (2 * i - n + 1);
			}
		}
		ans = min(ans, result);
	}
	printf("%d", ans);
	return 0;
}