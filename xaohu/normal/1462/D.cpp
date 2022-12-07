#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n, a[3005];

bool partition(int x, int exp) {
	int cnt = 0;
	int s = 0;
	rep(i, 0, n) {
		s = (s + a[i]) % x;
		if (s == 0)
			cnt++;
	}
	return cnt == exp;
}

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		ll s = 0;
		rep(i, 0, n)
			cin >> a[i], s += a[i];
		per(i, 1, n + 1)
			if (s % i == 0 && partition(s / i, i)) {
				cout << n - i << "\n";
				break;
			}
	}
	return 0;
}