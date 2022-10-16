#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

unsigned q, l, r, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	for(cin >> q; q--; ) {
		cin >> l >> r >> d;
		cout << (l > d ? d : (r/d+1)*d) << endl;
	}
}