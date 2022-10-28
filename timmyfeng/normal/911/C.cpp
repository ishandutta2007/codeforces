#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a(3);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	if (a[0] == 1) {
		cout << "YES" << '\n';
	} else if (a[0] == 2 && a[1] == 2) {
		cout << "YES" << '\n';
	} else if (a[0] == 2 && a[1] == 4 && a[2] == 4) {
		cout << "YES" << '\n';
	} else if (a[0] == 3 && a[2] == 3) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}