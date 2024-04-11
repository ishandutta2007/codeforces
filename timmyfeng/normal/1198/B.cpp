#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int q;
	cin >> q;
	vector<int> last(n);
	vector<int> req(q + 1);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int p, x;
			cin >> p >> x;
			a[p - 1] = x;
			last[p - 1] = i + 1;
		} else {
			cin >> req[i];
		}
	}

	for (int i = q; i; --i) {
		req[i - 1] = max(req[i - 1], req[i]);
	}

	for (int i = 0; i < n; ++i){
		cout << max(a[i], req[last[i]]) << " ";
	}
	cout << "\n";
}