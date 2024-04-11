#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		
		vector<int> nests;
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			if (a == 1) nests.push_back(1);
			else {
				while (nests.back() != a - 1)
					nests.pop_back();
				++nests.back();
			}
			for (int j = 0; j < (int) nests.size(); ++j) {
				if (j) cout << ".";
				cout << nests[j];
			}
			cout << "\n";
		}
	}
}