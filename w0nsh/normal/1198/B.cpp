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
 
VI repr, size, gdzie;
 
int Find(int a){
	if(repr[a] == a) return a;
	return repr[a] = Find(repr[a]);
}
 
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	repr[a] = b;
}
 
std::set<PII> sr;
std::map<int, int> map;
int fre;
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	repr.resize(2000000);
	size.resize(2000000);
	FOR(i, 2000000) repr[i] = i;
	FOR(i, 2000000) size[i] = 0;
	gdzie.resize(n);
	FOR(i, n){
		int a;
		std::cin >> a;
		if(map.count(a) == 0) map[a] = fre++, size[map[a]] = a, sr.insert(MP(a, map[a]));
		size[map[a]] = a;
		gdzie[i] = map[a];
	}
	int q;
	std::cin >> q;
	FOR(i, q){
		int what;
		std::cin >> what;
		if(what == 1){
			int p, x;
			std::cin >> p >> x;
			p--;
			map[x] = fre++, size[map[x]] = x, sr.insert(MP(x, map[x]));
			gdzie[p] = map[x];
		}else{
			int x;
			std::cin >> x;
			if(map.count(x) == 0) map[x] = fre++, size[map[x]] = x, sr.insert(MP(x, map[x]));
			auto it = sr.begin();
			while(it != sr.end() && it->X < x){
				auto next = std::next(it, 1);
				Union(it->Y, next->Y);
				sr.erase(it);
				it = next;
			}
		}
	}
	FOR(i, n){
		std::cout << size[Find(gdzie[i])] << " ";
	}
	return 0;
}