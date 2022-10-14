#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vi a(n), b(n);
	for(auto &i : a)
		cin >> i;
	for(auto &i : b)
		cin >> i;

	int ans = 5e8;

	rep(i, 0, n) {
		int left = i - 1;
		int right = i + 1;
		vi x, y;
		int mnl = 1e9, mnr = 1e9;
		for(; left >= 0; --left) {
			if(a[left] < a[i])
				mnl = min(mnl, b[left]);
		}
		for(; right < n; ++right) {
			if(a[right] > a[i])
				mnr = min(mnr, b[right]);
		}
		ans=min(ans,mnl+b[i]+mnr);

	}
	if(ans==5e8)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}