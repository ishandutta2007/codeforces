#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n, k;
	cin >> n >> k;
	ll lb=1, rb=2*k;
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		if(mb-mb/n>=k)
			rb=mb;
		else
			lb=mb+1;
	}
	cout << lb << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}