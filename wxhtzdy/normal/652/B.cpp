#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int i = 0, j = n - 1;
	while (i <= j) {
		cout << a[i] << " ";
		if(i != j) {
			cout << a[j] << " ";
		}
		i++; j--;
	}
}