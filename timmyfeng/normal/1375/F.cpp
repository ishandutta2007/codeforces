#include <bits/stdc++.h>
using namespace std;

long long a[3];

int play(long long y) {
	cout << y << endl;
	int res;
	cin >> res;
	--res;
	a[res] += y;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (auto& i : a) {
		cin >> i;
	}

	cout << "First" << endl;

	int res = play(*max_element(a, a + 3));

	res = play(3 * a[res] - accumulate(a, a + 3, 0LL));

	assert(play(a[res] - accumulate(a, a + 3, 0LL) / 3) == -1);
}