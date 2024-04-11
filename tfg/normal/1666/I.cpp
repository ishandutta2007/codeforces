#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		auto scan = [&](int i, int j)->int{
			cout << "SCAN " << i + 1 << " " << j + 1 << endl;
			int x;
			cin >> x;
			return x;
		};
		auto dig = [&](int i, int j)->bool{
			cout << "DIG " << i + 1 << " " << j + 1 << endl;
			bool x;
			cin >> x;
			return x;
		};
		array<int, 2> x{-1, -1}, y{-1, -1};

		int a = scan(0, 0), b = scan(n - 1, 0);
		int ysum = a + b - 2 * (n - 1);
		assert(~ysum & 1);
		ysum >>= 1;
		int xpivot = a - ysum >> 1;
		int c = scan(xpivot, 0);
		for(auto i = 0; i <= xpivot; ++ i){
			for(auto j = xpivot; j < n; ++ j){
				if(i + j == a - ysum && j - i == c - ysum){
					x = {i, j};
					goto XDONE;
				}
			}
		}
		XDONE:;
		assert(~x[0] && ~x[1]);

		b = 2 * (n - 1 + m - 1) - b;
		int xsum = a + b - 2 * (m - 1);
		assert(~xsum & 1);
		xsum >>= 1;
		int ypivot = a - xsum >> 1;
		c = scan(0, ypivot);
		for(auto i = 0; i <= ypivot; ++ i){
			for(auto j = ypivot; j < m; ++ j){
				if(i + j == a - xsum && j - i == c - xsum){
					y = {i, j};
					goto YDONE;
				}
			}
		}
		YDONE:;
		assert(~y[0] && ~y[1]);

		if(dig(x[0], y[0])){
			assert(dig(x[1], y[1]));
		}
		else{
			assert(dig(x[0], y[1]) && dig(x[1], y[0]));
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////