#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a=-1, b;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> b;
		if(b>a+1) {
			cout << i+1;
			return 0;
		}
		a=max(b, a);
	}
	cout << -1;
}