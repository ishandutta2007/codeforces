#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, char> a[300020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &a[i].first, &a[i].second);
	}
	long long ans = 0;
	int lastR = -1;
	int lastB = -1;
	int firstGindex = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].second == 'R') {
			if (lastR != -1) {
				ans += a[i].first - lastR;
			}
			lastR = a[i].first;
		}
		if (a[i].second == 'B') {
			if (lastB != -1) {
				ans += a[i].first - lastB;
			}
			lastB = a[i].first;
		}
		if (a[i].second == 'G') {
			firstGindex = i;
			break;
		}
	}
	if (firstGindex != -1) {
		if (lastR != -1) {
			ans += a[firstGindex].first - lastR;
		}
		if (lastB != -1) {
			ans += a[firstGindex].first - lastB;
		}
//		printf("%d\n", ans);
		for (int i = firstGindex + 1; i < n; i++) {
			if (a[i].second == 'G') {
				lastR = a[firstGindex].first;
				lastB = a[firstGindex].first;
				int maxGapR = 0;
				int maxGapB = 0;
				for (int j = firstGindex + 1; j <= i; j++) {
					if (a[j].second == 'R' || a[j].second == 'G') {
						maxGapR = max(maxGapR, a[j].first - lastR);
						lastR = a[j].first;
					}
					if (a[j].second == 'B' || a[j].second == 'G') {
						maxGapB = max(maxGapB, a[j].first - lastB);
						lastB = a[j].first;
					}
				}
//				cerr << maxGapR << ' ' << maxGapB << endl;
				long long fuck1 = (a[i].first - a[firstGindex].first) * 3LL - maxGapR - maxGapB;
				long long fuck2 = (a[i].first - a[firstGindex].first) * 2LL;
//				cerr << fuck1 << ' ' << fuck2 << endl;
				ans += min(fuck1, fuck2);
				firstGindex = i;
			}
		}
		lastR = a[firstGindex].first;
		lastB = a[firstGindex].first;
		for (int i = firstGindex + 1; i < n; i++) {
			if (a[i].second == 'R') {
				if (lastR != -1) {
					ans += a[i].first - lastR;
					lastR = a[i].first;
				}
			}
			if (a[i].second == 'B') {
				if (lastB != -1) {
					ans += a[i].first - lastB;
					lastB = a[i].first;
				}
			}
			assert(a[i].second != 'G');
		}
	}
	printf("%lld\n", ans);
	return 0;
}