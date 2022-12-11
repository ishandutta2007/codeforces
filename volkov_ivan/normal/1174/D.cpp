#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n, x;
	cin >> n >> x;
	set <int> all;
	vector <int> ans;
	ans.push_back(0);
	for (int i = 1; i < (1 << n); i++) {
		if (i == x) continue;
		all.insert(i);
	}
	while (!all.empty()) {
		int t = *all.begin();
		all.erase(t);
		all.erase(t ^ x);
		ans.push_back(t);
	}
	cout << (int) ans.size() - 1 << endl;
	for (int i = 1; i < (int) ans.size(); i++) {
		cout << (ans[i] ^ ans[i - 1]) << ' ';
	}
	return 0;
}