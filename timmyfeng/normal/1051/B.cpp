#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long l, r;
	cin >> l >> r;
	cout << "YES" << '\n';
	for (long long i = l; i < r; i += 2) {
		cout << i << ' ' << i + 1 << '\n';
	}
}