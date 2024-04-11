#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int t;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> s;
		string c = "ANOT";
		string res;
		long long best = -1;
		do {
			string q;
			string cur = s;
			long long inv = 0;
			for (auto x : c) {
				string new_;
				int cnt = 0;
				for (auto y : cur) {
					if (y == x) {
						q += x;
						inv += cnt;
					}
					else {
						new_ += y;
						cnt++;
					}
				}
				cur = new_;
			}
			if (inv > best) {
				best = inv;
				res = q;
			}
		} while (next_permutation(c.begin(), c.end()));
		cout << res << "\n";
	}			
	return 0;
}