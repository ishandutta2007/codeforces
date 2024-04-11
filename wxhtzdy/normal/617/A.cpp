#include <bits/stdc++.h>

using namespace std;

int main() {
	int x;
	cin >> x;
	int ans = x / 5;
	if (x % 5 != 0) {
	 	ans++;
	}
	cout << ans;
}