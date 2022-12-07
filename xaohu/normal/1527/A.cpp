#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (1 << (int)log2(n)) - 1 << "\n"; 
	}
	return 0;
}