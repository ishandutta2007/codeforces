#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		long long x;
		cin >> x;
		cout << (x >= 14 && 1 <= x % 14 && x % 14 <= 6 ? "YES" : "NO") << "\n";
	}
}