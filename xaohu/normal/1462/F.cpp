#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 200200;

int T, n, l[N], r[N], a[N], b[N];

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n) {
			cin >> l[i] >> r[i];
			a[i] = l[i];
			b[i] = r[i];
		}
		sort(a, a + n);
		sort(b, b + n);
		int res = n;
		rep(i, 0, n) {
			int x = lower_bound(b, b + n, l[i]) - b;
			int y = n - (upper_bound(a, a + n, r[i]) - a);
			res = min(res, x + y);
		}
		cout << res << "\n";
	}
	return 0;
}