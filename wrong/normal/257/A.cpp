#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k, a[50];

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a+n);
	reverse(a, a+n);

	int cur = k, u;
	for (u = 0; cur < m && u < n; ++u) {
		cur += a[u] - 1;
	}

	cout << (cur < m ? -1 : u) << endl;

	return 0;
}