#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <int> h(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int ans = h[0] + n;
	for (int i = 1; i < n; i++) {
		ans += abs(h[i] - h[i - 1]) + 1;
	}
	printf("%d", ans);
	return 0;
}