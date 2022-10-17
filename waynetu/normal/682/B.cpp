#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int c[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		c[i] = i + 1;
	}
	sort(a, a + n);
	int ans;
	int i = 0, j = 0;
	while (i < n) {
		if (a[i] >= c[j]) {
			a[i++] = c[j++];
		} else {
			i++;
		}
	}
	cout << a[n - 1] + 1 << endl;
	return 0;
}