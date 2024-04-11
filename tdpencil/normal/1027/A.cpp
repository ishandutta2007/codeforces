#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
constexpr int mxN=1e4;
int n, m;
string labels[mxN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >>t;
	while(t--) {
		cin >> n;
		string s; cin >> s;
		int l = 0, r = n - 1;
		bool y = 1;
		while(l < r) {
			y &= abs(s[l] - s[r]) % 2 == 0;
			y &= abs(s[l] - s[r]) <= 2;
			++l;
			--r;
		}

		cout << (y?"YES":"NO") << "\n";
	}	
}