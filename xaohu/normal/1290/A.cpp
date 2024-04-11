#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n, m, k, t[3505];

int main() { 
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		rep(i, 0, n)
			cin >> t[i];
		
		int res = 0;
		k = min(k, m - 1);

		rep(a, 0, k + 1) {
			int cur = 1e9;
			int b = k - a;
			rep(c, 0, m - 1 - k + 1) {
				int d =  m - 1 - k - c;
				cur = min(cur, max(t[a + c], t[n - 1 - b - d]));
			}
			res = max(res, cur);
		}

		cout << res << "\n";
	}
	return 0;
}