#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int sign(int x) {
	if (x == 0) {
		return 0;
	}
	if (x < 0) {
		return -1;
	}
	return 1;
}

int main() {
	int n, cnt = 0, a, b, x, now_x, now_y;
	cin >> n;
	int y[n];
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	bool visited[n];
	for (int start = 0; start < 2; start++) {
		for (int i = start + 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[j] = 0;
			}
			a = i - start;
			b = y[i] - y[start];
			x = gcd(a, abs(b));
			a /= x;
			b /= x;
			now_x = start;
			now_y = y[start];
			cnt = 0;
			//cout << start << ' ' << i << ' ' << now_y << ' ' << a << ' ' << b << endl;
			while (now_x < n) {
				if (y[now_x] == now_y) {
					visited[now_x] = 1;
					cnt++;
				}
				now_x += a;
				now_y += b;
			}
			if (cnt == n) {
				continue;
			}
			if (start == 1) {
				if (cnt == n - 1) {
					if (a == 1 && b == y[1] - y[0]) {
						continue;
					} else {
						cout << "YES" << endl;
						return 0;
					}
				}
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (!visited[j]) {
					now_x = j;
					now_y = y[j];
					break;
				}
			}
			while (now_x < n) {
				if (y[now_x] == now_y) {
					cnt++;
				}
				now_x += a;
				now_y += b;
			}
			if (cnt == n) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}