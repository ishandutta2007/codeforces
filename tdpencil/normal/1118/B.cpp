#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	
	vector<int> a(n);
	
	int ePref = 0, oPref = 0, eSf = 0, oSf = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i & 1) eSf += a[i];
		else oSf += a[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) eSf -= a[i];
		else oSf -= a[i];
		if (ePref + oSf == oPref + eSf) {
			++ans;
		}
		if (i & 1) ePref += a[i];
		else oPref += a[i];
	}
	
	cout << ans << endl;
	
	return 0;
}