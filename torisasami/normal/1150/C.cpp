#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int i, n, ans[222222], c[3], t=0,a;
	c[1] = 0;
	c[2] = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		c[a]++;
	}
	if (c[2] > 0) {
		ans[t] = 2;
		t++;
		c[2]--;
	}
	if (c[1] > 0) {
		ans[t] = 1;
		t++;
		c[1]--;
	}
	while (c[2] > 0) {
		ans[t] = 2;
		t++;
		c[2]--;
	}
	while (c[1] > 0) {
		ans[t] = 1;
		t++;
		c[1]--;
	}
	for (i = 0; i < n; i++) {
		cout << ans[i];
		if (i != n - 1)
			cout << " ";
		else
			cout << endl;
	}
}