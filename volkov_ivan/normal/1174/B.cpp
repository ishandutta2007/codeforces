#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	bool odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) even = 1;
		else odd = 1;
	}
	if (even && odd) {
		sort(a, a + n);
	}
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
	return 0;
}