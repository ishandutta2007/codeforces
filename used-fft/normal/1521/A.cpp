#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int a, b; cin >> a >> b;
		if(b == 1){
			cout << "NO\n";
		}else	cout << "YES\n" << a << ' ' << (b+b-1LL) * a << ' ' << a * b * 2 << '\n';
	}
}