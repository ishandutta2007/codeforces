#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int sum = 0;
		for(int i=0; i<n; ++i){
			int v; cin >> v;
			sum += v;
		}

		if(sum % n)
			cout << 1;
		else
			cout << 0;
		cout << '\n';
	}
}