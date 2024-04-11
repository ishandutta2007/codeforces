#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;

int last[MX];
int dsu[MX];
int cnt[MX];
int a[MX];

int find(int a) {
	if (dsu[a] < 0)
		return a;
	dsu[a] = find(dsu[a]);
	return dsu[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;

	if (dsu[a] < dsu[b]) {
		swap(a, b);
	}
	dsu[b] += dsu[a];
	dsu[a] = b;

	cnt[b] = max(cnt[b], cnt[a]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		last[a[i]] = i;
		++cnt[a[i]];
	}

	set<int> cur;
	memset(dsu, -1, sizeof dsu);
	for (int i = 0; i < n; ++i) {
		if (!cur.count(a[i])) {
			if (!cur.empty()) {
				unite(*cur.begin(), a[i]);
			}
			cur.insert(a[i]);
		}
		if (i == last[a[i]]) {
			cur.erase(a[i]);
		}
	}

	int ans = n;
	for (int i = 1; i < MX; ++i) {
		if (find(i) == i) {
			ans -= cnt[i];
		}
	}
	cout << ans << "\n";
}