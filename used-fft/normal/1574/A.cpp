#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		for(int i=0; i<n; ++i){
			cout << "(";
			for(int j=0; j<i; ++j) cout << "()";
			cout << ")";
			for(int j=0; j+i+2<=n; ++j) cout << "()";
			cout << '\n';
		}
	}
}