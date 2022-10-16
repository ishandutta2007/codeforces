#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

const int N = 1e5+7;

int n, x, y, h, w;
char op;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	for(cin >> n; n--; ) {
		cin >> op >> h >> w;
		if(h < w) swap(h, w); 

		if(op == '+') {
			y = max(y, h);
			x = max(x, w);
		}

		if(op == '?') {
			cout << (x <= w && y <= h ? "YES" : "NO") << endl;
		}
	}
}