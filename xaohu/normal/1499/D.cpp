#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 2e7 + 10;

int T, cnt[N], c, d, x;

int work(int g) {
	int a = x / g + d;
	if (a % c) return 0;
	return 1 << cnt[a / c];
}

void solve() {
	cin >> c >> d >> x;
	int res = 0;
	rep(g, 1, x) {
		if (g * g > x) break;
		if (x % g == 0) {
			res += work(g);
			if (g * g != x)
				res += work(x / g);
		}
	}	
	cout << res << endl;
}
 
int main() {
	rep(i, 2, N - 1) 
		if (!cnt[i]) 
			rep(j, 1, (N - 1) / i)
				cnt[i * j]++;
	cin >> T;
	while (T--) solve();
	return 0;
}