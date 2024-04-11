#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef long long LL;
int n, minv, minv2, minv3, cnt1, cnt2, cnt3, a[maxn];
LL ans;
int main() {
	scanf("%d", &n);
	minv = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i] == minv) ++cnt1;
		else if (a[i] < minv) minv = a[i], cnt1 = 1;
	}
	if (cnt1 >= 3) {
		ans = 1LL * cnt1 * (cnt1 - 1) * (cnt1 - 2) / 6;
	}
	else {
		minv2 = INT_MAX;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > minv) {
				if (a[i] < minv2) minv2 = a[i], cnt2 = 1;
				else if (a[i] == minv2) ++cnt2;
			}
		}
		
		if (cnt1 == 2) {
			ans = cnt2;
		}
		else { //cnt1 == 1
			if (cnt2 >= 2) ans = 1LL * cnt2 * (cnt2 - 1) / 2;
			else { //cnt2 == 1
				minv3 = INT_MAX;
				for (int i = 1; i <= n; ++i) {
					if (a[i] > minv2) {
						if (a[i] < minv3) minv3 = a[i], cnt3 = 1;
						else if (a[i] == minv3) ++cnt3;
					}
				}
				
				ans = cnt3;
			}
		}
	}
	cout << ans << endl;
}