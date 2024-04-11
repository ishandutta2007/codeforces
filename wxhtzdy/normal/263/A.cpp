#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			cin >> x;
			if (x) {
				n =i;
				m = j;
			}
		}
	}
	n++;
	m++;
	cout << abs(3 - n) + abs(3 - m);
}