#include <bits/stdc++.h>
using namespace std;

int a[200005], al, ar;

int main() {
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		int n; scanf("%d", &n);
		al = ar = -1;
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		// (a[r] - r) - (a[l] - l) >= 1
		int Min = 1000000000, Mint = 0;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] - i <= Min) {
				Min = a[i] - i;
				Mint = i;
			}
			if (a[i] - i - Min >= 1) {
				al = Mint; ar = i;
			}
		}
		if (al == -1) {
			int Min = 1010000000, Mint = 0;
			// a[l] - a[r] >= r - l + 1
			for (int i = n; i >= 1; -- i) {
				if (a[i] + i <= Min) {
					Min = a[i] + i;
					Mint = i;
				}
				if (a[i] + i - Min >= 1) {
					ar = Mint; al = i;
				}
			}
		}
		if (al == -1) printf("NO\n");
		else printf("YES\n%d %d\n", al, ar);
	}
	return 0;
}