#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

ll ask(int a){
	std::cout << "? " << a+1 << std::endl;
	ll x;
	std::cin >> x;
	return x;
}

void ans(int a){
	std::cout << "! " << a+1 << std::endl;
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	FOR(_, 500){
		ask(0);
	}

	int step = 450;
	step = std::min(step, n/2-2);
	step = std::max(step, 1);
	int sma = -1;
	int big = -1;
	for(int i = 0; i < n; i += step){
		ll xd = ask(i);
		if(xd > k){
			big = i;
		}
		if(xd < k){
			sma = i;
		}
	}
	assert(sma != -1 && big != -1);
	assert(sma != big);
	int left = 1;
	int right = big-sma;
	if(right < 0) right += n;
	right--;
	assert(left <= right);
	while(left <= right){
		int mid = (left+right)/2;
		int ind = (sma + mid)%n;
		ll xd = ask(ind);
		if(xd == k){
			ans(ind);
		}else if(xd > k){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}

	assert(false);

	return 0;
}