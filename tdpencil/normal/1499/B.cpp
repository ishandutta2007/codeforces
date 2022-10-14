#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
int a[200005];
int n, m;
string s;
void solve() {
	cin >> s;

	bool o=0,z=0;

	int n = s.size();
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i-1]) {
			if(s[i] == '0')  {
				o=1;
			} else if(s[i] == '1') {
				z=1;
			}

			if(s[i] == '0') {
				if(z) {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}