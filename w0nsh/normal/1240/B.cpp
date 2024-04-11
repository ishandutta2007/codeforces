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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		std::set<int> set;
		FOR(i, n) set.insert(A[i]);
		std::map<int, int> map;
		int fre = 0;
		TRAV(i, set) map[i] = fre++;
		TRAV(i, A) i = map[i];
		VI first(SZ(set), -1);
		VI last(SZ(set), -1);
		FOR(i, n) if(first[A[i]] == -1) first[A[i]] = i;
		FOR(i, n) last[A[i]] = i;
		VI score(SZ(set), 0);
		score[0] = 1;
		REP(i, 1, SZ(set)){
			if(last[i-1] < first[i]) score[i] = score[i-1]+1;
			else score[i] = 1;
		}
//asdsadsad
		std::cout << SZ(set)-*std::max_element(score.begin(), score.end()) << "\n";
	}
	return 0;
}