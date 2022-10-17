#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	int t, n, arr[200000];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		int i;
		for (i = 0; i < n - 1 && abs(arr[i] - arr[i + 1]) <= 1; ++i);
		if (i == n - 1) cout << "NO\n";
		else cout << "YES\n" << i + 1 << ' ' << i + 2 << '\n';
	}
	return 0;
}