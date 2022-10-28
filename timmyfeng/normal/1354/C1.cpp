#include <bits/stdc++.h> 
using namespace std;

const double PI = 3.1415926535897932384;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << 1.0 / tan(PI / 2 / n) << '\n';
	}
}