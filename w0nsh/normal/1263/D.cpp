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

int mat[26][26];
int repr[26];

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	repr[a] = b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	FOR(i, 26) repr[i] = i;
	std::set<int> let;
	FOR(i, n){
		std::string s;
		std::cin >> s;
		std::set<int> xd;
		TRAV(j, s) let.insert(j-'a'), xd.insert(j-'a');
		TRAV(j, xd) TRAV(k, xd) Union(j, k);
	}
	std::set<int> ans;
	TRAV(i, let) ans.insert(Find(i));
	std::cout << SZ(ans);
	return 0;
}