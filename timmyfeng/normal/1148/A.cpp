#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
	if (b > a + 1) {
		b = a + 1;
	}
	if (a > b + 1) {
		a = b + 1;
	}
	cout << a + b + c * 2 << "\n";
}