#include <iostream>
#include <algorithm>

using namespace std;

int simulate(int a[2])
{
	int cnt = 0, prev = 0, n = a[0] + a[1];
	a[0]--;

	for (int i = 1; i < n; ++i) {
		int use;

		if (a[0] == 0 || a[1] == 0) {
			use = a[0] == 0 ? 1 : 0;
		} else if (i % 2 == 1) {
			use = 1 - prev;
		} else {
			use = prev;
		}

		a[use]--;
		if (use == prev) {
			cnt++;
		}

		prev = use;
	}

	return cnt;
}

int main()
{
	int n[2], m[2], s = 0;

	cin >> n[0] >> n[1];
	m[0] = n[1]; m[1] = n[0];
	s = n[0] + n[1];

	int p = max(simulate(n), simulate(m));

	cout << p << " " << (s - 1 - p) << endl;

	return 0;
}