#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
int t, n, a[111000];
 
int main() {
	cin >> t;
	while (t--) {
		vector<int> ans;
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) 
			if (i == 1 || i == n || (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
				ans.push_back(a[i]);
		cout << ans.size() << "\n";
		for (auto x : ans)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}