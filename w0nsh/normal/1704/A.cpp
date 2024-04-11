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
	int n, m;
	std::cin >> n >> m;
	std::string A, B;
	std::cin >> A >> B;
	bool good = false;
	bool was0 = false;
	bool was1 = false;
	if(A == B) good = true;
	FOR(i, SZ(A)){
		if(A[i] == '0') was0 = true;
		else was1 = true;
		if(was0){
			std::string cur;
			cur.push_back('0');
			cur += A.substr(i+1);
			if(cur == B) good = true;
		}
		if(was1){
			std::string cur;
			cur.push_back('1');
			cur += A.substr(i+1);
			if(cur == B) good = true;
		}
	}
	if(good){
		std::cout << "YES\n";
	}else{
		std::cout << "NO\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}