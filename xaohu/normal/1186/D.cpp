#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int n;
double t[1 << 20], ans[1 << 20];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	long long s = 0;
	
	cin >> n;
	rep(i, 1, n) {
		cin >> t[i];
		ans[i] = floor(t[i]);
		s += ans[i];
	}
	
	rep(i, 1, n) {
		if (s < 0 && t[i] - ans[i]) {
			ans[i]++;
			s++;
		}
		cout << ans[i] << "\n";
	}
	
	return 0;
}