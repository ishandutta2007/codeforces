#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

int n, k, last = -1, cur, cl, ml;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	while(n--) {
		cin >> cur;

		cl = cur - last ? ++cl : 1;
		ml = ml > cl ? ml : cl;
		last = cur;
	}

	cout << ml;
}