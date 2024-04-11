#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		int one = 0;
		int zero = 0;
		while (n--) {
			int b;
			cin >> b;
			if (b) {
				++one;
			} else {
				++zero;
			}
		}

		if (!one || !zero) {
			vector<int> aa(a);
			sort(aa.begin(), aa.end());
			cout << (aa == a ? "Yes" : "No") << '\n';
		} else {
			cout << "Yes" << '\n';
		}
	}
}