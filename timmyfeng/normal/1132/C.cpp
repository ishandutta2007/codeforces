#include <bits/stdc++.h>
using namespace std;

const int MX = 5e3;

int l[MX], r[MX], cnt[MX + 1], ps1[MX + 1], ps2[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		cin >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; ++j) {
			++cnt[j];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += !!cnt[i];
		ps1[i] = ps1[i - 1] + (cnt[i] == 1);
		ps2[i] = ps2[i - 1] + (cnt[i] == 2);	
	}

	int ans = 0;
	for (int i = 0; i < q; ++i) {
		for (int j = i + 1; j < q; ++j) {
			int a = i;
			int b = j;
			if (l[a] > l[b]) {
				swap(a, b);
			}
			int cur = res;
			if (r[a] >= l[b]) {
				cur -= ps1[l[b] - 1] - ps1[l[a] - 1];
				cur -= ps2[min(r[a], r[b])] - ps2[l[b] - 1];
				cur -= ps1[max(r[a], r[b])] - ps1[min(r[a], r[b])];
			} else {
				cur -= ps1[r[a]] - ps1[l[a] - 1];
				cur -= ps1[r[b]] - ps1[l[b] - 1];
			}
			ans = max(cur, ans);
		}
	}
	cout << ans << '\n';
}