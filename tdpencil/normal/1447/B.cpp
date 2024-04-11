#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
int n, m;
string s;
bool isp(int d) {
	return d<0;
}
void solve() {
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m));
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j], ans+=abs(a[i][j]);


	int res=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			res+=isp(a[i][j]);

	if(res%2==0) {
		cout << ans << "\n";	
	} else {
		int mn = INT_MAX;
		for(int i = 0; i < n; i++) {
			for(int j=0;j<m;j++)
				mn=min(mn, abs(a[i][j]));
		}
		cout << ans - 2 * mn << "\n";
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}