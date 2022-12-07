#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		cout << (n - 1 + (m - 1) * n == k ? "YES\n" : "NO\n");
	}
	
	return 0;
}