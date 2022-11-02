#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		
		int x = 0, y = 0;
		string s = to_string(n);
		for(char i : s){
			x = x * 10 + (i - '0');
			n /= 10;
			swap(x, y);
		}

		int res = (x + 1) * (y + 1) - 2;

		cout << res << '\n';
	}	
}