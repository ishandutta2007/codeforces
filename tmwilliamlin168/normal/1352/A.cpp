#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	int p=1;
	while(n) {
		if(n%10)
			ans.push_back(n%10*p);
		n/=10;
		p*=10;
	}
	cout << ans.size() << "\n";
	for(int a : ans)
		cout << a << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}