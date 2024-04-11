#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	long long a = 1, b = 1;
	while (a < n && s[a] == s[a - 1]) {
		++a;
	}
	while (b < n && s[n - 1 - b] == s[n - b]) {
		++b;
	}

	cout << (s[0] == s[n - 1] ? (a + 1) * (b + 1) % 998244353 : 1 + a + b) << '\n';
}