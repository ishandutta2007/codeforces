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

	int n, k;
	std::cin >> n >> k;

	if(k == 1){
		std::cout << "Yes\n";
		return 0;
	}

	VI A(n);

	std::vector<PII> need;

	int cur = 2;
	while(k > 1){
		int cnt = 0;
		while(k % cur == 0){
			k /= cur;
			cnt++;
		}
		if(cnt) need.push_back(MP(cur, cnt));
		cur++;
	}

	std::vector<bool> done(SZ(need));

	FOR(i, n){
		std::cin >> A[i];
		int ind = 0;
		TRAV(pr, need){
			int cnt = 0;
			while(A[i] % pr.X == 0) cnt++, A[i] /= pr.X;
			if(cnt >= pr.Y) done[ind] = true;
			ind++;
		}
	}

	FOR(i, SZ(done)) if(done[i] == false){
		std::cout << "No\n";
		return 0;
	}
	std::cout << "Yes\n";

	

	return 0;
}