#include <bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define pb push_back
#define pi pair<int, int>
const int mxN = 2e5 + 1;

int n, a, b;


int main() {
	cin >> n >> a >> b;
	int ans = 0;
	
	for(int i = 1; i < n; i++) {
		int rest = n - i;
		int toA = a / i;
		int toB = b / rest;
		
		ans = max(ans, min(toA, toB));
	}
	cout << ans << "\n";
}