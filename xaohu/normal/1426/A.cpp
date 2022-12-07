#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
typedef long long ll;	
using namespace std;

int T, n, x;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> x;
		if (n <= 2) {
			cout << 1 << "\n";
		}
		else {
			cout << (n - 3) / x + 2 << "\n";
		}
	}
	return 0;
}