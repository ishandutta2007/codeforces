#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		int n, s, t;
		cin >> n >> s >> t;
		cout << max(n-s+1, n-t+1) << "\n";
	}
}