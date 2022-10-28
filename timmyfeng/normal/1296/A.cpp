#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		int odd = 0, even = 0;
		while (n--) {
			int a;
			cin >> a;
			sum += a;
			if (a % 2) {
				++odd;
			} else { 
				++even;
			}
		}
		if (sum % 2 || odd && even) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}