#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int asks = 997;

pair <int, int> elems[asks + 1];

pair <int, int> ask(int id, int n) {
	int value, next;
	cout << "? " << id << endl;
	cin >> value >> next;
	return make_pair(value, next);
}

int my_lower_bound(int x) {
	int left = 0, right = asks + 1, mid;
	while (right - left > 1) {
		mid = (right + left) / 2;
		if (elems[mid].first < x) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}

int main() {
	int n, x, start;
	pair <int, int> now;
	cin >> n >> start >> x;
	srand(1000);
	elems[0] = ask(start, n);
	for (int i = 1; i <= asks; i++) {
		elems[i] = ask(((rand() * RAND_MAX + rand()) % n) + 1, n);
	}
	sort(elems, elems + asks + 1);
	now = elems[my_lower_bound(x)];
	while (now.first < x && now.second != -1) {
		now = ask(now.second, n);
	}
	if (now.first < x) {
		cout << "! -1" << endl;
	} else {
		cout << "! " << now.first << endl;
	}
	return 0;
}