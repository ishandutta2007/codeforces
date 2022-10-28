#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int a, b;
	cin >> a >> b;
	if (a == 9 && b == 1) cout << 9 << ' ' << 10 << '\n'; 
	else if (a != b && a + 1 != b) cout << -1 << '\n';
	else if (a == b) cout << a << 0 << ' ' << b << 1 << '\n';
	else cout << a << 9 << ' ' << b << 0 << '\n';
}