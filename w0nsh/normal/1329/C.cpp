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

void solve(){
	int h, g;
	std::cin >> h >> g;
	VI A(1<<(h+1));
	REP(i, 1, 1<<h) std::cin >> A[i];

	bool dry_run;
	std::function<int(int)> fun = [&](int i){
		int lef = i*2;
		int rig = lef+1;
		if(A[lef] == 0 && A[rig] == 0){
			if(!dry_run) A[i] = 0;
			return i;
		}
		int which = (A[lef] > A[rig] ? lef : rig);
		if(!dry_run) A[i] = A[which];
		return fun(which);
	};

	VI ans;
	REP(i, 1, 1<<h){
		dry_run = true;
		while(A[i] && fun(i) >= (1<<g)){
			ans.push_back(i);
			dry_run = false;
			fun(i);
			dry_run = true;
		}
	}

	ll sum = 0;
	REP(i, 1, 1<<g) sum += A[i];
	std::cout << sum << "\n";
	TRAV(i, ans) std::cout << i << " ";
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}