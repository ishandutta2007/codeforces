#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;

int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		int s = 0;
		rep(i, 1, n) {
			int x; cin >> x;
			s += x;
		}
		if (s >= n) 
			cout << s - n << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}