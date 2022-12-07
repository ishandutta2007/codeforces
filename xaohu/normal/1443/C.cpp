#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n;
pair<ll, ll> t[321000];

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n)
			cin >> t[i].first;
		rep(i, 0, n)
			cin >> t[i].second;
		sort(t, t + n);
		ll res = 1e18, sum = 0;
		per(i, 0, n) {
			res = min(res, max(t[i].first, sum));
			sum += t[i].second;
		}
		res = min(res, sum);
		cout << res << "\n";
	}
	return 0;
}