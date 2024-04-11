#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int r, b, d; cin >> r >> b >> d;
		if(r > b) swap(r, b);
		if(b > (1LL + d) * r) cout << "NO\n";
		else cout << "YES\n";
	}
}