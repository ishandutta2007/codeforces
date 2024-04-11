#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << a[0] << " ";
	long long x = a[0];
	for (int i = 1; i < n; i++) {
		long long number = a[i] + x;
		cout << number << " ";
		x = max(x, number);
	}
	return 0;
}