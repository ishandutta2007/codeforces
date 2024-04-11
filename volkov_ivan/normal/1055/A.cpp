#include <iostream>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	int a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int swap = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1 && b[i] == 1) swap = i;
	}
	if (a[1] == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (a[s] == 1 || (b[s] == 1 && swap >= s)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}