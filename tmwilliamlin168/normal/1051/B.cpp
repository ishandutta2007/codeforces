#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long l, r;
	cin >> l >> r;
	cout << "YES\n";
	while(l<r) {
		cout << l << " " << l+1 << "\n";
		l+=2;
	}
}