#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > up, dn, z, tmp;
void upd(vector<pair<pair<int, int>, int> > a) {
	if (z.size() < a.size()) {
		z = a;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < y) {
			up.push_back(make_pair(make_pair(x, y), i));
		} else {
			dn.push_back(make_pair(make_pair(x, y), i));
		}
	}
	if (up.size() > dn.size()) {
		for (int i = 0; i < up.size(); i++) {
			swap(up[i].first.first, up[i].first.second);
		}
		sort(up.begin(), up.end());
		reverse(up.begin(), up.end());
		z = up;
	} else {
		sort(dn.begin(), dn.end());
		z = dn;
	}
	printf("%d\n", (int)z.size());
	for (int i = 0; i < z.size(); i++) {
		printf("%d%c", z[i].second, i == z.size() - 1 ? '\n' : ' ');
	}
	return 0;
}