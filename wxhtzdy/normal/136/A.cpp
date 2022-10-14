#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
	 	int x;
	 	cin >> x;
	 	a[x - 1] = i + 1;
 	}
 	for (int i = 0; i < n; i++) {
 	 	cout << a[i] << " ";
 	}
}