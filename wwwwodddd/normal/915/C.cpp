#include <iostream>
#include <cstdio>
using namespace std;
long long a, b;
long long t[20];
int c[10];
void dfs(int x, long long y) {
	if (x < 0) {
		cout << y << endl;
		exit(0);
	}
	for (int i = 9; i >= 0; i--) {
		if (c[i] > 0 && y + i * t[x] <= b) {
			c[i]--;
			dfs(x - 1, y + i * t[x]);
			c[i]++;
		}
	}

}
int main() {
	cin >> a >> b;
	int cnt = 0;
	while (a > 0) {
		c[a % 10]++;
		cnt++;
		a /= 10;
	}
	for (int i = t[0] = 1; i < 20; i++) {
		t[i] = t[i - 1] * 10;
	}
	dfs(cnt - 1, 0);
	return 0;
}