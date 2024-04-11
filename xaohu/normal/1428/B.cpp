#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int T, n;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;
		int res = 0;
		if (!count(s.begin(), s.end(), '>') || !count(s.begin(), s.end(), '<')) {
			res = n;
		}
		else {
			rep(i, 0, n)
				res += (s[i] == '-' || s[(i + 1) % n] == '-');
		}
		cout << res << endl;
	}

	return 0;
}