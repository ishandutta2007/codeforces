#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	long long a, b;
	scanf("%I64d %I64d", &a, &b);
	long long ans = 0;
	while (true) {
		if (b == 0) {
			break;
		}
		if (a % b == 0) {
			ans += a;
			break;
		}
		if (a > b) {
			ans += a / b;
			a %= b;
		} else {
			ans += b / a;
			b %= a;
		}
	}
	printf("%I64d", ans);
	return 0;
}