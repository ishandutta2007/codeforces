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

int n, repr[150005];
VI vec[150005];

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
	int ra = Find(a);
	int rb = Find(b);
	if(SZ(vec[ra]) > SZ(vec[rb])){
		TRAV(i, vec[rb]) vec[ra].push_back(i); 
		repr[rb] = ra;
	}else{
		TRAV(i, vec[ra]) vec[rb].push_back(i); 
		repr[ra] = rb;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) repr[i] = i, vec[i].push_back(i);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		Union(a, b);
	}
	int xd = Find(0);
	TRAV(i, vec[xd]) std::cout << i +1 << " ";
	return 0;
}