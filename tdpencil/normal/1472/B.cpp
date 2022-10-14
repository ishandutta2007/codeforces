#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int(x.size()))
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		
		ll ans = 0;
		for(int i=0; i < n; i++) {
			cin >> a[i]; ans += a[i];
		}
		
		if(ans % 2 == 1) {
			cout << "NO\n";
			continue;
		}
		
		ans /= 2;
		
		sort(a.begin(), a.end());
		
		for(int i = n-1; i >=0; i--) {
			if(a[i] <= ans)
				ans -= a[i];
		}
		
		if(ans == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
}