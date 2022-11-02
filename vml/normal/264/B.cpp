#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector <int> result(100001);
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 2; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				res = max(res, result[j]);
				res = max(res, result[a[i] / j]);
			}
		}
		res = max(res, result[a[i]]);
		res++;
		for (int j = 2; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				result[j] = res;
				result[a[i] / j] = res;
			}
		}
		result[a[i]] = res;
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		ans = max(ans, result[a[i]]);
	}
	printf("%d", ans);
	return 0;
}