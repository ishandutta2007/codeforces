#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, a, b, t;
	std::cin >> n >> a >> b >> t;

	std::string s;
	std::cin >> s;

	s += s;
	s += s;


	int start = 2*n;

	auto check = [&](int k){
		int l = start-k+1;
		int r = start;

		int bad = 0;
		REP(i, l, r+1) if(s[i] == 'w') bad++;

		auto calc = [&](){
			int one = start-l;
			int two = r-start;
			return one+two+std::min(one, two);
		};

		while(l <= start){
			if(calc()*a+bad*b <= t-k) return true;

			if(s[l] == 'w') bad--;
			l++;
			r++;
			if(s[r] == 'w') bad++;
		}

		return false;
	};

	int left = 1;
	int right = n+1;

	while(left < right){
		int mid = (left+right)/2;
		if(check(mid)) left = mid+1;
		else right = mid;
	}

	std::cout << left-1 << "\n";


	return 0;
}