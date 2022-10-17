#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

#define int long long
int n;
VI A;

// bool is_square(ll a){
// 	int left = 1;
// 	int right = 1000000001;
// 	while(left < right){
// 		int mid = (left+right)/2;
// 		if(1ll*mid*mid == a) return true;
// 		else if(1ll*mid*mid < a) left = mid+1;
// 		else right = mid;
// 	}
// 	return false;
// }

void fail(){
	std::cout << "No";
	std::exit(0);
}

std::vector<VI> divisors;
std::vector<VI> ids;
std::vector<ll> ans;

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	n /= 2;
	A.resize(n);
	divisors.resize(n);
	ids.resize(200005);
	FOR(i, n) std::cin >> A[i], ids[A[i]].push_back(i);
	for(int i = 1; i <= 200005; ++i){
		for(int j = i; j <= 200005; j += i){
			TRAV(xd, ids[j]) divisors[xd].push_back(i);
		}
	}
	int last = 0;
	ll have = 0;
	FOR(i, n){
		have += A[i];
		int min = 1000000000;
		TRAV(dv, divisors[i]){
			int a = dv;
			int b = A[i]/a;
			// std::cout << a << " " << b << std::endl;
			if(a % 2 != b % 2) continue;
			int cand = (a+b)/2;
			if(cand > last && cand < min && cand*cand > have) min = cand;
		}
		if(min == 1000000000) fail();
		ll next = min*min;
		ll x = min*min-have;
		ans.push_back(x);
		last = min;
		have += x;
	}
	std::cout << "Yes\n";
	// TRAV(i, ans) std::cout << i << " ";
	FOR(i, 2*n){
		if(i % 2 == 0) std::cout << ans[i/2] << " ";
		else std::cout << A[i/2] << " ";
	}
	return 0;
}