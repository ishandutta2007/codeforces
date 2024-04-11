#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int n, a[111000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	rep(i, 1, n + 1)
		cin >> a[i];

	vector<pair<int, int>> res;
	vector<int> v23, v3;
	auto add = [&](int a, int b) {
		res.push_back({a, b});
	};
	
	per(i, 1, n + 1) {
		if (a[i] == 1) {
			add(i, i);
			v23.push_back(i);
		}
		if (a[i] >= 2) {
			vector<int> &v = (a[i] == 2 ? v23 : (!v3.empty() ? v3 : v23));
			if (v.empty()) {
				cout << "-1\n";
				return 0;
			}
			else {
				if (a[i] == 2) {
					add(v.back(), i);
				}
				else {
					add(i, i);
					add(i, v.back());
				}
				v.pop_back();
			}
			v3.push_back(i);
		}
	}

	cout << res.size() << endl;
	for (auto [a, b] : res)
		cout << a << " " << b << endl;
	return 0;
}