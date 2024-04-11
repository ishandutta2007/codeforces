#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--){
		int a, b, c; cin >> a >> b >> c;

		bool ok = (a + b == c || a + c == b || b + c == a);

		if(a == b && !(c & 1)) ok = 1;
		if(a == c && !(b & 1)) ok = 1;
		if(b == c && !(a & 1)) ok = 1;

		cout << (ok ? "YES" : "NO") << '\n';
	}
}