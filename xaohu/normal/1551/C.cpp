#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> s(n);
		for (auto& i : s)
			cin >> i;
		int res = 0;
		for (int c = 0; c < 5; c++) {
			vector<int> v;
			for (auto x : s) {
				int bil = 0;
				for (auto i : x)
					bil += (i - 'a' == c ? 1 : -1);
				v.push_back(bil);
			}
			sort(v.rbegin(), v.rend());
			int s = 0;
			int cur = 0;
			for (auto b : v)
				if (s + b > 0) {
					s += b;
					cur++;
				}
			res = max(res, cur);
		}
		cout << res << endl;
	}
	return 0;
}