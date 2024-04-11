#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	for (int _ = 0; _ < 1; ++_) {
	int a[3], l;
	scanf("%d%d%d%d", a, a + 1, a + 2, &l);
	sort(a, a + 3);
	long long ans = 0;
	for (int i = a[2]; i <= a[2] + l; ++i) {
		for (int j = 0; j < 3; ++j) {
			int b[2], ll;
			if (j == 0) {
				b[0] = a[1], b[1] = a[2], ll = l - (i - a[0]);
			}
			if (j == 1) {
				b[0] = a[0], b[1] = a[2], ll = l - (i - a[1]);
			}
			if (j == 2) {
				b[0] = a[0], b[1] = a[1], ll = l - (i - a[2]);
			}
			int bar0 = i - b[0], bar1 = i - b[1];
			if (j == 1) {
				--bar0;
			}
			if (j == 2) {
				--bar0, --bar1;
			}
			if (ll >= 0) {
				if (b[0] + b[1] + ll > i) {
					int rr = min(ll, bar0 + bar1);
					ll = max(0, i - b[0] - b[1] + 1);
					if (ll <= rr) {
						if (bar0 > bar1) {
							swap(bar0, bar1);
						}
						bar0 = min(bar0, rr), bar1 = min(bar1, rr);
						if (bar0 >= ll) {
							//ll - bar0
							if (bar0 >= ll) {
								ans += (long long)(ll + 1 + bar0 + 1) * (bar0 - ll + 1) / 2;
							}
							//bar0 + 1, bar1
							if (bar1 >= bar0 + 1) {
								ans += (long long)(bar0 + 1) * (bar1 - bar0);
							}
							//bar1 + 1 - rr
							if (rr >= bar1 + 1) {
								ans += (long long)(bar0 + bar0 - (rr - bar1) + 1) * (rr - bar1) / 2;
							}
						} else if (bar1 >= ll) {
							//bar0 + 1, bar1
							if (bar1 >= ll) {
								ans += (long long)(bar0 + 1) * (bar1 - ll + 1);
							}
							//bar1 + 1 - rr
							if (rr >= bar1 + 1) {
								ans += (long long)(bar0 + bar0 - (rr - bar1) + 1) * (rr - bar1) / 2;
							}
						} else {
							//bar1 + 1 - rr
							if (rr >= ll) {
								ans += (long long)(bar0 - (ll - bar1) + bar0 - (rr - bar1) + 2) * (rr - ll + 1) / 2;
							}
						}
						/*
						cout << i << ' ' << j << ' ' << ans << endl;
						cout << ll << ' ' << rr << endl;
						cout << bar0 << ' ' << bar1 << endl;
						*/
					}
				}
			}
		}
	}
	cout << ans << endl;
	}
	return 0;
}