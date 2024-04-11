#include <bits/stdc++.h>
using namespace std;

int complement(int num, int limit) {
	return (num-1)^limit;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--) {
		int x=0;
		int n;
		cin >> n;
		for(int i=0;i<n;i++) {
			int a;
			cin >> a;
			x|=a;
		}

		cout << x << "\n";
	}
}