#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[3];
int n, x;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		x--;
		a[x].push_back(i);
	}
	int ans = min(min(a[0].size(), a[1].size()), a[2].size());
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		cout << a[0][i] << ' ' << a[1][i] << ' ' << a[2][i] << endl;
	}
	return 0;
}