#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n / 2);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n / 2; ++i) {
		ans1 += abs(i * 2 + 1 - a[i]);
		ans2 += abs(i * 2 + 2 - a[i]);
	}
	cout << min(ans1, ans2) << '\n';
}