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

std::vector<VI> g;
VI state;

int HEH[2];
VI col;
void dfs(int v, int cl){
	col[v] = cl;
	if(cl == state[v]) HEH[0]++;
	else HEH[1]++;
	TRAV(ch, g[v]){
		if(col[ch] != -1){
			assert(col[ch] != cl);
		}else{
			dfs(ch, 1-cl);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<PR<PII, int>> A;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if((a >= n) == (b >= n)){
			std::cout << "-1\n";
			return 0;
		}
		A.push_back(MP(MP(a, b), 0));
		if(a > b){
			A[i].Y = 1;
			std::swap(A[i].X.X, A[i].X.Y);
		}
	}
	std::sort(A.begin(), A.end());
	g.resize(n);

	std::set<PII> set;
	state.resize(n);
	FOR(i, n) set.insert(MP(A[i].X.Y, i));
	std::vector<bool> dead(n);

	FOR(i, n){
		set.erase(MP(A[i].X.Y, i));
		state[i] = A[i].Y;

		auto it = set.end();
		std::vector<PII> mam;
		while(it != set.begin()){
			it--;
			if(it->X < A[i].X.Y){
				break;
			}

			if(dead[i]){
				std::cout << -1 << "\n";
				return 0;
			}
			g[i].push_back(it->Y);
			g[it->Y].push_back(i);
			dead[it->Y] = true;
			mam.push_back(*it);
		}

		FOR(j, SZ(mam)-1){
			if(mam[j].Y > mam[j+1].Y){
				std::cout << -1 << "\n";
				return 0;
			}
			set.erase(mam[j]);
		}
	}

	int ans = 0;
	col.resize(n, -1);
	FOR(i, n) if(col[i] == -1){
		HEH[0] = HEH[1] = 0;
		dfs(i, 0);
		ans += std::min(HEH[0], HEH[1]);
	}
	std::cout << ans << "\n";

	

	return 0;
}