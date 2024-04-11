#include <bits/stdc++.h>
using namespace std;
void solve() {
	
		int n; cin >> n;
		string s; cin >> s;
		int last = 1 + (s[0] - '0');
		string ans;
		ans += "1";
		for(int i = 1; i < n; ++i) {
			if((s[i] - '0') + 1 == last) {
				ans += "0";
			} else {
				ans += "1";
			}
			last = (s[i] - '0' + (ans[i] - '0') );
		}

		cout << ans << endl;
}
int main()
{
	int t; cin >> t;

	while(t--) {
		solve();
	}
}