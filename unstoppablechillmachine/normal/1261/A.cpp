#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<pair<int, int>> ans;
		for (int i = 0; i < 2 * (k - 1); i++) {
			if (i % 2 == 0) {
				if (s[i] != '(') {
					int ptr = i + 1;
					while (s[ptr] == ')') {
						ptr++;
					}
					reverse(s.begin() + i,  s.begin() + ptr + 1);
					ans.pb({i + 1, ptr + 1});
				}
			}
			else {
				if (s[i] != ')') {
					int ptr = i + 1;
					while (s[ptr] == '(') {
						ptr++;
					}
					reverse(s.begin() + i,  s.begin() + ptr + 1);
					ans.pb({i + 1, ptr + 1});	
				}
			}
		}
		int cnt = (n - 2 * (k - 1)) / 2;
		//cout << "KEK " << cnt << '\n';
		//cout << s << '\n';
		for (int i = 2 * (k - 1); i < n; i++) {
			if (i - 2 * (k - 1) + 1 <= cnt) {
				if (s[i] != '(') {
					int ptr = i + 1;
					while (s[ptr] == ')') {
						ptr++;
					}
					//cout << i + 1 << ' ' << ptr + 1 << '\n';
					reverse(s.begin() + i,  s.begin() + ptr + 1);
					ans.pb({i + 1, ptr + 1});	
				}
			}
			else {
				if (s[i] != ')') {
					int ptr = i + 1;
					while (s[ptr] == '(') {
						ptr++;
					}
					reverse(s.begin() + i,  s.begin() + ptr + 1);
					ans.pb({i + 1, ptr + 1});	
				}	
			}
		}
		cout << SZ(ans) << '\n';
		for (auto it : ans) {
			cout << it.F << ' ' << it.S << '\n';
		}
		//cout << s << '\n';
	}
}