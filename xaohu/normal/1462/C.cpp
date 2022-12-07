#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, x, res;

void rec(int d, int s, int n) {
	if (d == 10) {
		if (s == x)
			res = min(res, n);
		return;
	}
	rec(d + 1, s + d, 10 * n + d);
	rec(d + 1, s, n);
}

int main() { 
	cin >> T;
	while (T--) {
		cin >> x;
		res = 1e9;
		rec(1, 0, 0);
		if (res == 1e9)
			res = -1;
		cout << res << "\n";
	}
	return 0;
}