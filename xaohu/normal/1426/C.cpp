#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
typedef long long ll;	
using namespace std;

int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		int res = 2e9;
		for (int i = 1; i <= 60000; i++)
			res = min(res, i - 1 + (n - 1) / i);
		cout << res << "\n";
	}
	return 0;
}