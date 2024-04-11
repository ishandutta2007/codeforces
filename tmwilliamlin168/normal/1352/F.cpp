#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if(!b) {
		if(a) {
			for(int i=0; i<=a; ++i)
				cout << 0;
			cout << "\n";
		} else {
			for(int i=0; i<=c; ++i)
				cout << 1;
			cout << "\n";
		}
	} else {
		for(int i=0; i<a; ++i)
			cout << 0;
		cout << "01";
		--b;
		for(int i=0; i<c; ++i)
			cout << 1;
		int d=0;
		while(b) {
			cout << d;
			d^=1;
			--b;
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}