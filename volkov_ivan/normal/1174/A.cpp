#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n;
	cin >> n;
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(a, a + 2 * n);
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) s1 += a[i];
	for (int i = n; i < 2 * n; i++) s2 += a[i];
	if (s1 == s2) cout << "-1" << endl;
	else {
		for (int i = 0; i < 2 * n; i++) cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}