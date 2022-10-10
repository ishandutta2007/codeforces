#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int len, n;
	cin >> len >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	auto check_low = [&](int low)->bool{
		int left = 0;
		for(auto x: a){
			if(x < left){
				return false;
			}
			left = max(x, left + low);
			if(left > len){
				return false;
			}
		}
		return true;
	};
	int low = *ranges::partition_point(ranges::iota_view(1, len + 1), check_low) - 1;
	auto check_high = [&](int high)->bool{
		int left = 0;
		for(auto x: a){
			left = min(left, x) + high;
			if(left < x){
				return true;
			}
		}
		return left < len;
	};
	int high = *ranges::partition_point(ranges::iota_view(1, len), check_high);
	a.push_back(len);
	vector<array<int, 2>> dp(n + 1);
	for(auto i = 0; i < n; ++ i){
		dp[i + 1] = {max(a[i], dp[i][0] + low), min(a[i + 1], dp[i][1] + high)};
		assert(dp[i + 1][0] <= dp[i + 1][1]);
	}
	assert(dp[n][0] <= len && len <= dp[n][1]);
	vector<int> res(n + 1, len);
	for(auto i = n - 1; i >= 0; -- i){
		res[i] = clamp(res[i + 1] - high, dp[i][0], dp[i][1]);
		assert(res[i] <= res[i + 1] && low <= res[i + 1] - res[i] && res[i + 1] - res[i] <= high);
	}
	for(auto i = 0; i < n; ++ i){
		cout << res[i] << " " << res[i + 1] << "\n";
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