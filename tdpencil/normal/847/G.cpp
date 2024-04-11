#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
int n, m;
string s;
void solve() {
	int n; cin >> n;
	vector<string> a(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < 7; i++) {
		int c=0;
		for(int j = 0; j < n; j++) {
			if(a[j][i]=='1')c++;
		}
		ans=max(ans, c);
	}

	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; //cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}