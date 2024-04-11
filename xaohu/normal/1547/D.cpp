#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

int n;

void solve() {
	cin >> n;
	int last = 0;
	rep(i, 0, n) {
		int x;
		cin >> x;
		int y = 0;
		rep(b, 0, 30)
			if (last >> b & 1)
				if (!(x >> b & 1))
					y += 1 << b;
		cout << y << " ";
		last = x + y;
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}