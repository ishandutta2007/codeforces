#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main() {
	while (cin >> n) {
		LL l = 0, r = 1e8;
		while (l + 1 < r) {
			LL mid = (l + r) / 2;
			if (mid * (mid + 1) /2 < n) l = mid;
			else r = mid;
		}
		//cout << l << " ";
		n -= l * (l + 1) / 2;
		cout << n << endl;
	}
}