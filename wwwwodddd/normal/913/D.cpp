#include <bits/stdc++.h>
using namespace std;
set<pair<pair<int, int>, int> > can, in;
pair<pair<int, int>, int> a[200020];
int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first.first, &a[i].first.second);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		pair<pair<int, int>, int> b;
		b.first.first = a[i].first.second;
		b.first.second = a[i].first.first;
		b.second = a[i].second;
		can.insert(b);
	}
	int index = 0;
	int ans = 0;
	int currenttime = 0;
	for (int i = 1; i <= n; i++) {
		while (index < n && a[index].first.first < i) {
			pair<pair<int, int>, int> b;
			b.first.first = a[index].first.second;
			b.first.second = a[index].first.first;
			b.second = a[index].second;
			if (in.find(b) != in.end()) {
				currenttime -= b.first.first;
				in.erase(b);
			} else {
				can.erase(b);
			}
			index++;
		}
		while (in.size() < i && can.size()) {
			pair<pair<int, int>, int> b = *can.begin();
			can.erase(b);
			currenttime += b.first.first;
			in.insert(b);
		}
		if (currenttime <= t) {
			ans = max(ans, (int)in.size());
		}
	}
	can.clear();
	for (int i = 0; i < n; i++) {
		if (a[i].first.first >= ans) {
			pair<pair<int, int>, int> b;
			b.first.first = a[i].first.second;
			b.first.second = a[i].first.first;
			b.second = a[i].second;
			can.insert(b);
			while (can.size() > ans) {
				can.erase(--can.end());
			}
		}
	}
	printf("%d\n", ans);
	printf("%d\n", ans);
	for (auto i: can) {
		printf("%d ", i.second);
	}
	printf("\n");
	return 0;
}