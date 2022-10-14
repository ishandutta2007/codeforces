#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
#define nl "\n"
#define en "\n"
#define eb emplace_back
#define trav(i, j) for(auto &i : j)
#define FOR(i, P) for(int i = 0; i < int(P); i++)
#define all(x) x.begin(),x.end()
#define x first
#define y second
ll n, m, k;


void solve() {
	cin >> n;
	string s; cin >> s;

	int l = 0, r = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'L') {
			l--;
		} else if(s[i] == 'R') {
			r++;
		}
	}

	cout << (r - l + 1) << "\n";
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int t = 1; cin >> t;
	 int t = 1;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}