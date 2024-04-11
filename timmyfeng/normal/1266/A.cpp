#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		int sum = 0;
		int even = 0;
		bool zero = false;
		for (auto& i : s) {
			sum += i - '0';
			even += (i % 2 == 0);
			zero |= (i == '0');
		}
		cout << (sum % 3 == 0 && even >= 2 && zero ? "red" : "cyan") << "\n";
	}
}