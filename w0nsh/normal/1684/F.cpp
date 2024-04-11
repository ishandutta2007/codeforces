#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void compress(VI &A){
	VI vals = A;
	std::sort(vals.begin(), vals.end());
	vals.resize(std::distance(vals.begin(), std::unique(vals.begin(), vals.end())));
	auto kto = [&](int v){
		return std::distance(vals.begin(), std::lower_bound(vals.begin(), vals.end(), v));
	};

	TRAV(i, A) i = kto(i);
}

void solve(){
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	compress(A);
	std::vector<VI> where(n);
	FOR(i, n) where[A[i]].push_back(i);
	std::vector<PII> B(m);
	std::vector<std::vector<PII>> evs(n+1);
	FOR(i, m){
		std::cin >> B[i].X >> B[i].Y;
		B[i].X--;
		B[i].Y--;
		evs[B[i].X].push_back(MP(B[i].X, 1));
		evs[B[i].Y+1].push_back(MP(B[i].X, -1));
	}

	auto losu = [&]{
		return std::uniform_int_distribution<ll>(0, (1ll<<60) - 1)(rng);
	};

	std::vector<PII> prs;
	std::multiset<int> set;
	FOR(i, n){
		for(auto [ind, c] : evs[i]){
			if(c == 1){
				set.insert(ind);
			}else{
				set.erase(set.find(ind));
			}
		}

		if(SZ(set) == 0) continue;
		int from = *set.begin();

		auto prv = std::lower_bound(where[A[i]].begin(), where[A[i]].end(), i);
		if(prv != where[A[i]].begin()){
			--prv;
			if(*prv >= from){
				prs.push_back(MP(*prv, i));
				auto it = std::lower_bound(where[A[i]].begin(), where[A[i]].end(), from);
				if(it != prv){
					assert(*it < *prv && *it >= from);
					prs.push_back(MP(*it, i));
				}
			}
		}
	}

	// TRAV(i, prs){
	// 	std::cout << i.X << " " << i.Y << " || " << std::endl;
	// }

	std::vector<ll> xr(SZ(prs));
	TRAV(i, xr) i = losu();
	ll all = 0;
	TRAV(i, xr) all ^= i;

	auto check = [&](int k){
		std::vector<ll> dod(n);
		FOR(i, SZ(prs)){
			if(prs[i].X + k >= prs[i].Y){
				dod[prs[i].X] ^= xr[i];
				if(prs[i].Y + k < n){
					dod[prs[i].Y + k] ^= xr[i];
				}
			}else{
				dod[prs[i].X] ^= xr[i];
				dod[prs[i].X + k] ^= xr[i];
				dod[prs[i].Y] ^= xr[i];
				if(prs[i].Y + k < n){
					dod[prs[i].Y + k] ^= xr[i];
				}
			}
		}

		ll have = 0;
		bool good = false;
		TRAV(i, dod){
			have ^= i;
			if(have == all){
				good = true;
				break;
			}
		}
		return good;
	};

	int left = 0;
	int right = n+1;
	while(left < right){
		int mid = (left+right)/2;
		if(check(mid)) right = mid;
		else left = mid+1;
	}
	std::cout << left << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}