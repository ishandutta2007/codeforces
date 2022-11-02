#include <bits/stdc++.h>
using namespace std;
#define int long long

const int LIM = 3e5 + 5;

int X[LIM];

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	for(int i=1; i<LIM; ++i)
		X[i] = i ^ X[i-1];

	int T; cin >> T;
	while(T--){
		int a, b; cin >> a >> b;

		int val = X[a-1];


		if(val == b) cout << a << '\n';
		else{
			int y = val ^ b;
			cout << a + 1 + (y == a) << '\n';
		}
	}
}