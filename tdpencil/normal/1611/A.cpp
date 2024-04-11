#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define sz(x) (int(x.size()))
#define all(x) begin(x),end(x)
#define rep(i,j,k) for(int i=j; j<k; j++)
#define vi vector<int>
#define pii pair<int, int>



void solve() {
	string s; cin >> s;
	if((s[sz(s)-1]-'0')%2==0) {
		cout << "0" << "\n";
	} else if((s[0]-'0')%2==0) {
		cout << 1 << "\n";
	} else {
		for(char ch : s)
			if((ch-'0')%2==0) {
				cout << 2 << "\n";
				return;
			}
		cout << -1 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--)
		solve();
}