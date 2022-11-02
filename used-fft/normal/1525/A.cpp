#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int k; cin >> k;
		int a = k, b = 100-k;
		int c = __gcd(a, a+b);
		a /= c, b /= c;
		cout << a + b nl;
	}
}