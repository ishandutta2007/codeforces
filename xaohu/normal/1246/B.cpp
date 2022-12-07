#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n, k;
map<vector<pair<int, int>>, int> m;
ll res;

int main() {
	cin >> n >> k;
	rep(i, 0, n) {
		int x;
		cin >> x;
		vector<pair<int, int>> a, b;
		rep(j, 2, x + 1) {
			if (j * j > x)
				break;
			if (x % j) 
				continue;
			int cnt = 0;
			while (x % j == 0) {
				x /= j;
				cnt++;
			}
			cnt %= k;
			if (cnt) {
				a.emplace_back(j, k - cnt);
				b.emplace_back(j, cnt);
			}
		}
		if (x > 1) {
			a.emplace_back(x, k - 1);
			b.emplace_back(x, 1);
		}
		res += m[a];
		m[b]++;
	}
	cout << res;
	return 0;
}