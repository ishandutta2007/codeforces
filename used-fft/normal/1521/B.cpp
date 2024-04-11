#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i;
		int m = min_element(a, a+n) - a;

		cout << n-1 << '\n';

		int x = a[m], y = a[m] + 1;

		for(int i=0; i<n; ++i){
			if(i == m) continue;
			if(i < m) cout << i+1 << ' ' << m+1 << ' ' << ((i - m) & 1 ? y : x) << ' ' << x << '\n';
			else cout << m+1 << ' ' << i+1 << ' ' << x << ' ' << ((i - m) & 1 ? y : x) << '\n';
		}
	}
}