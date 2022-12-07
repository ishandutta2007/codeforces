#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n, x[1024], y[1024];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	rep(i, 0, n)
		cin >> x[i] >> y[i];
	while (1) {
		int cnt[2][2]{};
		rep(i, 0, n)
			cnt[abs(x[i]) % 2][abs(y[i]) % 2]++;
		vector<pair<int, int>> res;
		if (cnt[0][0] + cnt[1][1] && cnt[0][1] + cnt[1][0])
			res = {{0, 0}, {1, 1}};
		else if (cnt[0][0] && cnt[1][1])
			res = {{0, 0}};
		else if (cnt[0][1] && cnt[1][0])
			res = {{0, 1}};
		if (!res.empty()) {
			vector<int> ans;
			rep(i, 0, n)
				for (auto [a, b] : res)
					if (abs(x[i]) % 2 == a && abs(y[i]) % 2 == b)
						ans.push_back(i);
			cout << sz(ans) << endl;
			for (auto e : ans)
				cout << e + 1 << " ";
			return 0;
		}
		rep(i, 0, n) {
			x[i] -= abs(x[i]) % 2;
			y[i] -= abs(y[i]) % 2;
			x[i] /= 2;
			y[i] /= 2;
		}
	}
	return 0;
}