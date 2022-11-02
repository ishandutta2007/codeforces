#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int l, r; cin >> l >> r;
		int a = r;
		int b = max(l, (r+2)/2);
		cout << a % b nl;
	}	
}