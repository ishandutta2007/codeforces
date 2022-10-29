#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

struct re{
	int L[2], R[2];
}a[100005];

int n, id1[100005], id2[100005];

set <pii> S;

bool cmpl(const int &x, const int &y) {
	return a[x].L[0] < a[y].L[0];
}

bool cmpr(const int &x, const int &y) {
	return a[x].R[0] < a[y].R[0];
}

void ins_seg(int l, int r) {
	auto it = S.lower_bound(pii(l, r));
	while (it != S.end()) {
		if (it->first <= r + 1) {
			r = max(r, it->second);
			auto iit = it;
			++ iit;
			S.erase(it);
			it = iit;
		} else {
			break;
		}
	}
	if (it != S.begin()) {
		-- it;
		if (it->second >= l - 1) {
			l = min(l, it->first);
			r = max(r, it->second);
			S.erase(it);
		}
	}
	S.insert(pii(l, r));
}

bool chk_cov(int l, int r) {
	auto it = S.lower_bound(pii(l, r));
	if (it != S.end()) {
		if (it->first <= r) return true;
	}
	if (it != S.begin()) {
		-- it;
		if (it->second >= l) return true;
	}
	return false;
}

bool check() {
	sort(id1 + 1, id1 + 1 + n, cmpl);
	sort(id2 + 1, id2 + 1 + n, cmpr);
	S.clear();
	int t = 1;
	for (int i = 1; i <= n; ++ i) {
		while (t <= n && a[id2[t]].R[0] < a[id1[i]].L[0]) {
			ins_seg(a[id2[t]].L[1], a[id2[t]].R[1]);
			++ t;
		}
		if (chk_cov(a[id1[i]].L[1], a[id1[i]].R[1])) return true;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d%d", &a[i].L[0], &a[i].R[0], &a[i].L[1], &a[i].R[1]);
		id1[i] = id2[i] = i;
	}
	if (check()) printf("NO\n");
	else {
		for (int i = 1; i <= n; ++ i) {
			swap(a[i].L[0], a[i].L[1]);
			swap(a[i].R[0], a[i].R[1]);
		}
		if (check()) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}