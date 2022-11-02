#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[10] {};
		while(n--) {
			int b, d; cin >> b >> d;
			a[d-1] = max(a[d-1], b);
		}
		if(!*min_element(a, a + 10))
			cout << "MOREPROBLEMS\n";
		else cout << accumulate(a, a + 10, 0) << '\n';
	}
}