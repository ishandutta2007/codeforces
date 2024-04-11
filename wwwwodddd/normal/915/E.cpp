#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
// working = 0
// nonworking = 1;

pair<pair<int, int>, int> a[300020];
vector<int> lisan;
int n, q;
struct T{
	int label;
	int sum;
} t[4010020];
void build(int l, int r, int x) {
	if (l == r - 1) {
		return;
	}
	int m = (l + r) / 2;
	build(l, m, x * 2);
	build(m, r, x * 2 + 1);
}

void push(int l, int r, int x) {
	if (l < r - 1 && t[x].label) {
		t[x * 2].label = t[x].label;
		t[x * 2 + 1].label = t[x].label;
		if (t[x].label == 2) {
			t[x * 2].sum = 0;
			t[x * 2 + 1].sum = 0;
		} else {
			int m = (l + r) / 2;
			t[x * 2].sum = lisan[m] - lisan[l];
			t[x * 2 + 1].sum = lisan[r] - lisan[m];
		}
		t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
	}
	t[x].label = 0;
}

void change(int l, int r, int x, int L, int R, int v) {
//	printf("%d %d %d %d %d\n", l, r, x, L, R);
	if (r <= L || R <= l) {
		return;
	}
	if (L <= l && r <= R) {
		t[x].label = v;
		if (v == 2) {
			t[x].sum = 0;
		} else {
			t[x].sum = lisan[r] - lisan[l];
		}
		return;
	}
	push(l, r, x);
	int m = (l + r) / 2;
	change(l, m, x * 2, L, R, v);
	change(m, r, x * 2 + 1, L, R, v);
	t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
}
int main() {
	scanf("%d%d", &n, &q);
	int hello = n;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
		a[i].first.second++;
		lisan.push_back(a[i].first.first);
		lisan.push_back(a[i].first.second);
	}
	sort(lisan.begin(), lisan.end());
	lisan.resize(unique(lisan.begin(), lisan.end()) - lisan.begin());
	n = lisan.size();
//	build(0, n, 1);
	for (int i = 0; i < q; i++) {
		int L = lower_bound(lisan.begin(), lisan.end(), a[i].first.first) - lisan.begin();
		int R = lower_bound(lisan.begin(), lisan.end(), a[i].first.second) - lisan.begin();
		change(0, n, 1, L, R, a[i].second);
		printf("%d\n", hello - t[1].sum);
	}
	return 0;
}