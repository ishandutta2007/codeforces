#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, sign[100050], sign_s[100050], a[100050];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	sign[n - 1] = 1;
	sign_s[0] = 1;
	for (int i = n - 2; i >= 0; --i) {
		int plus = abs(a[i] + a[i + 1]);
		int minus = abs(a[i] - a[i + 1]);

		if (plus < minus) {
			sign[i] = 1;
			sign_s[i + 1] = 1;
		} else if (a[i] - a[i + 1] >= 0) {
			sign[i] = 1;
			sign_s[i + 1] = -1;
		} else {
			sign[i] = -1;
			sign_s[i + 1] = 1;
		}

		a[i] = min(plus, minus);
	}

	int cur_s = 1;
	for (int i = 0; i < n; ++i) {
		cur_s *= sign_s[i];
		putchar(cur_s * sign[i] < 0 ? '-' : '+');
	}

	puts("");

	return 0;
}