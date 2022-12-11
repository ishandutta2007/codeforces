#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int>> fact(int n) {
	vector <pair <int, int>> ans;
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			ans.push_back({i, 1});
			n /= i;
			while (n % i == 0) {
				n /= i;
				ans.back().second++;
			}
		}
		i++;
	}
	if (n > 1) {
		ans.push_back({n, 1});
	}
	return ans;
}

int find_log(int x) {
	int ans = 0, i = 1;
	while (i < x) {
		i *= 2;
		ans++;
	}
	return ans;
}

int main() {	
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1 0" << endl;
		return 0;
	}
	vector <pair <int, int>> t = fact(n);
	int ans1 = 1, maxi = 0;
	for (pair <int, int> elem : t) {
		ans1 *= elem.first;
		maxi = max(maxi, elem.second);
	}
	//cout << find_log(8) << endl;
	int ans2 = find_log(maxi);
	int d = 0, flag = 1;
	if (t.size() == 1 && t[0].second != (1 << ans2)) flag = 0;
	for (int i = 1; i < t.size(); i++) {
		if (t[i].second != (1 << ans2)) {
			flag = 0;
			break;
		}
		if (t[i].second != t[i - 1].second) {
			flag = 0;
			break;
		}
	}
	if (flag) d = 1;
	cout << ans1 << ' ' << ans2 + 1 - d << endl;
	return 0;
}