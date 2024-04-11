#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int t;
ll l, r;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for(cin >> t; t--; ) {
		cin >> l >> r;
		cout << l << ' ' << 2*l << endl;
	}
}