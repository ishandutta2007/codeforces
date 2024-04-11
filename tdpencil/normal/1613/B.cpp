#include <bits/stdc++.h>
using namespace std;


// tdp
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		sort(a.begin(), a.end());
		
		for(int i = 0; i < n / 2; i++)
			cout << a[i + 1] << " " << a[0] << "\n";
		
		
		
	}
}