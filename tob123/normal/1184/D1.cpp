#include <bits/stdc++.h>
using namespace std;

#define Debug(x) x
typedef int regular_int;
// #define int ll
typedef long long ll;

regular_int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

	int n, k, m;
	cin >> n >> k >> m;
	int t;
	cin >> t;
	while(t--) {
		int x, p;
		cin >> x >> p;
		if(x) {
			++n;
			if(p <= k)
				++k;
		} else {
			if(p < k) {
				k -= p;
				n -= p;
			} else {
				n = p;
			}
		}
		cout << n << " " << k << endl;
	}
	return 0;
}