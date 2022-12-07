#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n;
int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n < 9) 
			cout << 0 << endl;
		else
			cout << (n - 9) / 10 + 1 << endl;
	}
}