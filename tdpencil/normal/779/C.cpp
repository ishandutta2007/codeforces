#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
constexpr int mxN=1e4;
int n, m;
string labels[mxN];
bool cmp(ar<int, 2> x, ar<int, 2> y) {
	return x[0] - x[1] > y[0] - y[1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	int s = 0;
	vector<ar<int, 2>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i][0];
		s += a[i][0];
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i][1];
	}

	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < n - m; i++) {
		if(a[i][0] > a[i][1]) {
			s -= a[i][0] - a[i][1];
		}
	}

	cout << s << "\n";
}