#include <bits/stdc++.h>
#pragma GCC optimize("Ofast") // optimizes doubles + vectors
using namespace std;

#define pb push_back
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define ll long long
#define vi vector<int>
#define vt vector
#define vl vector<ll>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n, m;
const int mxN=2e5,M=1e9+7;
void solve(int test_case = 0) {
	ar<int, 2> a, b, c;

	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];	
	if(a[0] == b[0]) {
		if(a[1] > b[1])
		{
			swap(a, b);
		}
		if(c[1] > a[1] && c[1] <= b[1] && c[0] == a[0]) {
			cout << abs(b[1] - a[1]) + 2<< "\n";
		}
		else {
			cout << abs(b[1] - a[1]) + 0 << "\n";
		}
	} else if(a[1] == b[1]) {
		if(a[0] > b[0])
		{
			swap(a, b);
		}

		if(c[0] > a[0] && c[0] <= b[0] && c[1] == a[1]) {
			cout << abs(b[0] - a[0]) + 2 << "\n";
		}
		else {
			cout << abs(b[0] - a[0]) << "\n";
		}
	} else {
		cout << abs(a[0] - b[0]) + abs(a[1] - b[1]) << "\n";
	}
}

int main()
{
	// setup();
	cin.tie(0)->sync_with_stdio(0);
	//precalc();
	int T = 1;
	cin >> T;

	for(int nt = 0, i; nt < T; nt++) {
		solve();
		++i;

	}
}