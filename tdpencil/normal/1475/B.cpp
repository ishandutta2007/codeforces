#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector
const int mxN = 2e5;
ll n, m;
bool primes[int(1e7)];
void solve() {
	cin >> n;
	
	if(n % 2020 == 0) {
		cout << "YES\n";
		return;
	} else if(n % 2021 == 0) {
		cout << "YES\n";
		return;
	}

	while(n > 0) {
		if(n < 2020) break;
		if(n % 2020 == 0) n -= 2020;
		else if(n % 2021 == 0) n -= 2021;
		else if(n % 2 == 0) n -= 2020;
		else n -= 2021;
	}

	cout << (n == 0 ? "YES\n" : "NO\n");
}
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t = 1; cin >> t;
	while(t--)
		solve();
}