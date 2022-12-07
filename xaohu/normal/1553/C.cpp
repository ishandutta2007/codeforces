#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> s;
		int res = 10;
		for (auto win : {0, 1}) {
			int dif = 0;
			int matches = 5;
			for (int i = 0; i < 10; i++) {
				if (s[i] == '?')
					dif += (i % 2 == win ? 1 : 0);
				else if (s[i] == '1')
					dif += (i % 2 == win ? 1 : -1);
				if (i % 2 == !win)
					matches--;
				if (dif > matches)
					res = min(res, i + 1);
			}
		}
		cout << res << endl;
	}
}