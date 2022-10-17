#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

VI perm[200005];
std::map<VI, int> map;
int A[200005];
int g[125][125];
int last[125];

VI comp(VI a, VI b){
	VI ret(5);
	FOR(i, 5) ret[i] = b[a[i]];
	return ret;
}

int generate(VI &gen, std::vector<bool> &can){
	std::fill(can.begin(), can.end(), false);
	std::queue<int> que;
	int ret = SZ(gen);
	TRAV(i, gen) que.push(i), can[i] = true;
	while(SZ(que)){
		int v = que.front();
		que.pop();
		TRAV(i, gen){
			if(!can[g[i][v]]){
				can[g[i][v]] = true;
				ret++;
				que.push(g[i][v]);
			}
		}
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	REP(i, 1, n+1){
		perm[i].resize(5);
		FOR(j, k) std::cin >> perm[i][j], perm[i][j]--;
		REP(j, k, 5) perm[i][j] = j;
	}
	VI xd;
	FOR(i, 5) xd.push_back(i);
	int ind = 0;
	do{
		map[xd] = ind++;
	}while(std::next_permutation(xd.begin(), xd.end()));
	REP(i, 1, n+1) A[i] = map[perm[i]];
	TRAV(a, map){
		TRAV(b, map){
			g[a.Y][b.Y] = map[comp(a.X, b.X)];
		}
	}
	FOR(i, ind) last[i] = -1;
	ll ans = 0;
	REP(end, 1, n+1){
		std::vector<PII> vec;
		last[A[end]] = end;
		FOR(i, ind) if(last[i] != -1) vec.push_back(MP(last[i], i));
		std::sort(vec.begin(), vec.end(), std::greater<PII>());
		int ile = 1;
		int upto = end;
		std::vector<bool> can(ind, false);
		VI gen = {0};
		can[0] = true;
		TRAV(pr, vec) if(!can[pr.Y]){
			ans += (upto-pr.X)*ile;
			upto = pr.X;
			gen.push_back(pr.Y);
			ile = generate(gen, can);
		}
		ans += (upto-0)*ile;
	}
	std::cout << ans << "\n";
	return 0;
}