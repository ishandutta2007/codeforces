#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5;

int a[MX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	int cur = 0, i = 0;
	for (; i < n && cur < (sum + 1) / 2; ++i) {
		cur += a[i];
	}
	cout << i << '\n';
}