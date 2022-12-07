#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<int> pos;
		rep(i, 0, n - 1)
			if (s[i] == '*')
				pos.push_back(i);
		long long ans = 0;
		int mid = (pos.size() - 1) / 2, cnt = 0;
		rep(i, 0, (int)pos.size() - 1) {
			if (i <= mid) {
				ans += pos[mid] - pos[i];
				ans -= mid - i;
			}
			else {
				ans += pos[i] - pos[mid];
				ans -= i - mid;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}