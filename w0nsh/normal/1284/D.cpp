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

int n;
bool check(std::vector<PR<PII, PII> > A){
	auto it = A.begin();
	std::multiset<int> st, en;
	while(it != A.end()){
		int x = it->X.X;
		while(it != A.end() && x == it->X.X){
			if(it->X.Y == 1){
				st.insert(it->Y.X);
				en.insert(it->Y.Y);
			}else{
				st.erase(st.find(it->Y.X));
				en.erase(en.find(it->Y.Y));
			}
			it++;
		}
		if(SZ(st) > 0 && *en.begin() < *std::prev(st.end())) return false;
	}
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::vector<PR<PII, PII> > A;
	std::vector<PR<PII, PII> > B;
	FOR(i, n){
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		A.push_back(MP(MP(a, 1), MP(c, d)));
		A.push_back(MP(MP(b+1, -1), MP(c, d)));
		B.push_back(MP(MP(c, 1), MP(a, b)));
		B.push_back(MP(MP(d+1, -1), MP(a, b)));
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	if(check(A) && check(B)) std::cout << "YES\n";
	else std::cout << "NO\n";

	return 0;
}