#include <bits/stdc++.h>
#define pb push_back
 
using ll = long long;
using namespace std;

int t, a, b, c;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> a >> b >> c;
		cout << max({a, b, c}) << endl;
	}
	return 0;
}