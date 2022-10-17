#include <bits/stdc++.h>
using namespace std;
int f[120];
int main() {
	f[0] = 1;
	for (int i = 0; i <= 100; i++) {
		f[i + 3] |= f[i];
		f[i + 7] |= f[i];
	}
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (f[x]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}