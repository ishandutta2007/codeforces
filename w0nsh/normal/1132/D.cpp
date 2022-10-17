#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, k;
std::vector<ll> A, B;
std::vector<PR<int, PR<ll, int> > > data;


bool can(ll x){
	FOR(i, n) data[i] = MP(0, MP(A[i], B[i]));
	std::priority_queue<PII, std::vector<PII>, std::greater<PII> > set;
	FOR(i, n) if(A[i]/B[i] < k) set.push(MP((int)std::min(A[i]/B[i], 1000000000ll), i));
	int day = 0;
	while(day < k){
		if(set.empty()) return true;
		auto pr = set.top();
		set.pop();
		if(pr.X < day) return false;
		auto dt = data[pr.Y];
		// if(chrg > 1000000000000000ll) chrg = 1000000000000000ll;
		// std::cout << pr.X << " teraz " << day + chrg/pr.Y.Y.Y << "\n";
		ll chrg = dt.Y.X - 1ll*(day-dt.X)*dt.Y.Y + x;
		if(chrg/dt.Y.Y + day < k){
			set.push(MP(day + chrg/dt.Y.Y, pr.Y));
			data[pr.Y] = MP(day, MP(chrg, dt.Y.Y));
		}
		day++;
	}
	// TRAV(i, set) if(i.X < k-1) return false;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	data.resize(n);
	FOR(i, n){
		ll a;
		std::cin >> a;
		A.push_back(a);
	}
	FOR(i, n){
		ll a;
		std::cin >> a;
		B.push_back(a);
	}
	if(!can(2000000000200ll)){
		std::cout << -1;
		return 0;
	}
	// can(4);
	// return 0;
	ll left = 0ll;
	ll right = 2000000000200ll;
	if(can(10000000000ll)) right = 10000000000ll;
	else left = 10000000001ll;
	while(left < right){
		ll mid = (left+right)/2;
		if(can(mid)) right = mid;
		else left = mid+1;
	}
	std::cout << left;
	return 0;
}