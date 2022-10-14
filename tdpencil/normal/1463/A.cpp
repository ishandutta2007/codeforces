#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define P pair
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> t = {a, b, c};
	sort(t.begin(), t.end());
	if((a+b+c) % 9 == 0 &&  t[0] >= (a+b+c)/9) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);

	int tc;
	cin >> tc;
	while(tc--) {
		solve();
	}
}