#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
	for (int i = 0; i < (int)v.size(); i++) {
		if (n % v[i] == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}