#include <bits/stdc++.h>
using namespace std;
const int N = 205;
pair<int, int> seg[N];
bool lap(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) swap(a, b);
	if (a.second < b.first) return 0;
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int s, d;
		scanf("%d%d", &s, &d);
		bool flag = 1;
		for (int j = 1; j < i; ++ j) {
			if (lap(seg[j], make_pair(s, s + d - 1))) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			seg[i] = make_pair(s, s + d - 1);
			continue;
		}
		vector<int> all;
		all.push_back(1);
		for (int j = 1; j < i; ++ j) all.push_back(seg[j].second + 1);
		sort(all.begin(), all.end());
		for (int s : all) {
			bool flag = 1;
			for (int j = 1; j < i; ++ j) {
				if (lap(seg[j], make_pair(s, s + d - 1))) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				seg[i] = make_pair(s, s + d - 1);
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++ i) printf("%d %d\n", seg[i].first, seg[i].second);
}