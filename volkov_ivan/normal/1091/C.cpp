#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

vector <pair <int, int>> f(int n) {
	int i = 2;
	vector <pair <int, int>> res;
	while (i * i <= n) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			res.push_back(make_pair(i, cnt));
		}
		i++;
	}
	if (n != 1) {
		res.push_back(make_pair(n, 1));
	}
	return res;
}

vector <pair <int, int>> pr;
vector <int> all_divs;

void gen(int pos, int s) {
	if (pos == (int) pr.size()) {
		all_divs.push_back(s);
		return;
	}
	for (int i = 0; i <= (int) pr[pos].second; i++) {
		gen(pos + 1, s);
		s *= pr[pos].first;
	}
}

signed main() {
	int n;
	cin >> n;
	pr = f(n);
	gen(0, 1);
	vector <int> ans;
	for (int i = (int) all_divs.size() - 1; i >= 0; i--) {
		int x = all_divs[i];
		int cnt = n / x;
		ans.push_back(cnt * (2 + x * (cnt - 1)) / 2);
	}
	sort(ans.begin(), ans.end());
	for (int elem : ans) cout << elem << ' ';
	return 0;
}