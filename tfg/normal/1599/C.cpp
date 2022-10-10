#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	double temp;
	cin >> n >> temp;
	const int tot = 10000, p = round(temp * tot);
	auto C = [&](int n, int k)->int{
		if(k < 0 || n < k){
			return 0;
		}
		int res = 1;
		for(auto x = n; x > n - k; -- x){
			res = res * x / (n - x + 1);
		}
		return res;
	};
	for(auto x = 0; x <= n; ++ x){
		if(1LL * (C(x, 1) * C(n - x, 2) + 2 * C(x, 2) * C(n - x, 1) + 2 * C(x, 3) * C(n - x, 0)) * tot >= 2LL * p * C(n, 3)){
			cout << x << "\n";
			return 0;
		}
	}
	assert(false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////