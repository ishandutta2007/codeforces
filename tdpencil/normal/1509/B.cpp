
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define ar array


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	if(count(s.begin(), s.end(), 'T') != 2 * count(s.begin(), s.end(), 'M')) {
		cout << "NO\n";
		return;
	}

	int cnt = 0;
	for(auto &ch : s) {
		if(ch == 'T') cnt++;
		if(ch == 'M') cnt--;

		if(cnt < 0) {
			cout << "NO\n";
			return;
		}
	}
	cnt = 0;
	reverse(s.begin(), s.end());
	for(auto &ch : s) {
		if(ch == 'T') cnt++;
		if(ch == 'M') cnt--;

		if(cnt < 0) {
			cout << "NO\n";
			return;
		}
		
	}

	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}