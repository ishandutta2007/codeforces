#include<cstdio>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int n, h;
char name[10];

int main() {
	scanf("%s%d%d", name, &n, &h);
	if (name[0] == 'B') {
		printf("%d\n", n);
	} else {
		long double pow2[65];
		pow2[0] = 1;
		for (int i = 1; i < 65; ++i) {
			pow2[i] = pow2[i - 1] * 2;
		}
		long double ans = n;
		for (int i = 1; i <= h; ++i) {
			long double mul = 1;
			for (int j = 1; j <= n; ++j) {
				long double d = n - j;
				d *= 1 / pow2[i * 2];
				d *= mul;
				d *= pow2[i] - pow2[i - 1] * (1 + (j - 1) / (pow2[i] - 1));
				ans += d;
				mul *= (1 - 1 / pow2[i]);
			}
		}
		cout << fixed << setprecision(12) << ans << endl;
	}
	return 0;
}