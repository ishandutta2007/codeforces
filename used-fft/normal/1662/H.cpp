#include <bits/stdc++.h>
using namespace std;

vector<int> d(const int &n) {
	vector<int> res;
	for(int i = 1; i * i <= n; ++i)
		if(!(n % i)) res.push_back(i), res.push_back(n / i);
	return res;
}

const array<int, 2> subL[3] = {{0, 2}, {2, 0}, {1, 1}};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		vector<int> ans {1, 2};
		for(array<int, 2> sub : subL) {
			vector<int> c = d(gcd(n - sub[0], m - sub[1]));
			for(int i : c) ans.push_back(i);
		}
		sort(begin(ans), end(ans));
		ans.erase(unique(begin(ans), end(ans)), end(ans));
		cout << ans.size() << ' ';
		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}
}