#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int h, m;
		cin >> h >> m;
		cout << (23 - h) * 60 + 60 - m << '\n';
	}
}