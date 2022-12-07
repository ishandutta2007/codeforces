#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cout << n / 3 + (n % 3 == 1) << " " << n / 3 + (n % 3 == 2) << endl;
	}
	return 0;
}